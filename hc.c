#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

typedef struct {
    uint32_t p[512];
    uint32_t q[512];
    uint32_t counter1024;
    uint32_t keystream[16];
    uint32_t idx;
} HC128Context;

void Initialize(HC128Context *context, const uint8_t *key, const uint8_t *iv) {
    
}

void GenerateKeystream(HC128Context *context) {
  
}

uint32_t NextKeystreamWord(HC128Context *context) {
    
}

void Encrypt(HC128Context *context, const uint8_t *plaintext, uint8_t *ciphertext, size_t length) {
    
}

void Decrypt(HC128Context *context, const uint8_t *ciphertext, uint8_t *plaintext, size_t length) {
    
}

int main() {
    HC128Context context;
    uint8_t key[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
    uint8_t iv[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};

    Initialize(&context, key, iv);

    // dòng khóa
      const char *plaintext = "PRNG2021";
    size_t length = strlen(plaintext);

    uint8_t *ciphertext = (uint8_t *)malloc(length);
    Encrypt(&context, (const uint8_t *)plaintext, ciphertext, length);

    uint8_t *decrypted = (uint8_t *)malloc(length);
    Decrypt(&context, ciphertext, decrypted, length);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for (size_t i = 0; i < length; ++i) {
        printf("%02X", ciphertext[i]);
    }
    printf("\n");
    printf("Decrypted: %s\n", decrypted);

    free(ciphertext);
    free(decrypted);

    return 0;
}