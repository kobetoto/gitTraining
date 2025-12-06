// rsa_toy.cpp
#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
#include <tuple>

// calcule (a * b) % mod en évitant overflow (ici uint64_t suffit pour petits nombres)
uint64_t mulmod(uint64_t a, uint64_t b, uint64_t mod) {
    return (a * b) % mod;
}

// Exponentiation modulaire rapide : (base^exp) % mod
uint64_t modexp(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = mulmod(res, base, mod);
        base = mulmod(base, base, mod);
        exp >>= 1;
    }
    return res;
}

// Extended Euclidean Algorithm -> retourne (g, x, y) tel que a*x + b*y = g = gcd(a,b)
std::tuple<int64_t,int64_t,int64_t> extended_gcd(int64_t a, int64_t b) {
    if (b == 0) return {a, 1, 0};
    auto [g, x1, y1] = extended_gcd(b, a % b);
    int64_t x = y1;
    int64_t y = x1 - (a / b) * y1;
    return {g, x, y};
}

// Calcul de l'inverse modulaire: trouve d tel que (d * e) % phi = 1
int64_t modinv(int64_t e, int64_t phi) {
    auto [g, x, y] = extended_gcd(e, phi);
    if (g != 1) return -1; // pas d'inverse
    int64_t d = x % phi;
    if (d < 0) d += phi;
    return d;
}

// Génère une paire simplifiée (n, e) et d
void generate_keys(uint64_t p, uint64_t q, uint64_t &n, uint64_t &e, uint64_t &d) {
    n = p * q;
    uint64_t phi = (p - 1) * (q - 1);
    e = 17; // choix simple; devrait être coprime avec phi
    int64_t dinv = modinv((int64_t)e, (int64_t)phi);
    if (dinv == -1) {
        std::cerr << "Erreur: e n'a pas d'inverse mod phi\n";
        std::exit(1);
    }
    d = (uint64_t)dinv;
}

int main() {
    // --- Setup (Bob genère ses clés) ---
    // Petits premiers (toy example) :
    uint64_t p = 61; // NE PAS UTILISER EN PROD
    uint64_t q = 53;
    uint64_t n, e, d;
    generate_keys(p, q, n, e, d);

    std::cout << "Bob public key (n, e): (" << n << ", " << e << ")\n";
    std::cout << "Bob private key d: " << d << "\n\n";

    // --- Alice crée un message et chiffre char-par-char ---
    std::string alice_msg;
    std::cout << "Alice: entre un message court: ";
    std::getline(std::cin, alice_msg);

    // Chiffrement : chaque caractère -> entier m (0..255), puis c = m^e mod n
    std::vector<uint64_t> ciphertext;
    for (unsigned char ch : alice_msg) {
        uint64_t m = static_cast<uint64_t>(ch);
        uint64_t c = modexp(m, e, n);
        ciphertext.push_back(c);
    }

    std::cout << "\nAlice envoie (ciphertext): ";
    for (auto c : ciphertext) std::cout << c << ' ';
    std::cout << "\n\n";

    // --- Bob déchiffre avec sa clé privée d ---
    std::string bob_recovered;
    for (auto c : ciphertext) {
        uint64_t m = modexp(c, d, n);
        char ch = static_cast<char>(m);
        bob_recovered.push_back(ch);
    }

    std::cout << "Bob a déchiffré et obtient: " << bob_recovered << "\n";

    return 0;
}

