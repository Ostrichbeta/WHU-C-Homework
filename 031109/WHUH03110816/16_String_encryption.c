#include <stdio.h>
#include <string.h>
#define 整 int
#define 空 void
#define 字 char
#define 如 if
#define 否 else
#define 遍 for
#define 返 return
#define 概 main
#define 印 printf
#define 歪拗 while
#define 串長 strlen
#define 非 !
#define 得 scanf
#define 所指之物 [i]
#define 逾或為 >=
#define 逾 >
#define 弗如 <
#define 弗如或為 <=
#define 給 =
#define 為 ==
#define 自盈 +=
#define 自損 -=
#define 且 &&
#define 所指 i
#define 所指之處盈一 i++


//(Optional) Task 16: String encryption

//Normal Version

// void encrypt(char* original, int offset){
//     if (offset >= 10) {
//         printf("Offset out of range.");
//     } else {
//         for (int i = 0; i < strlen(original); i++) {
//             if (original [i] >= 65 && original [i] <= 90) {
//                 original [i] += offset;
//                 if (original [i] > 90){
//                     original [i] -= 26;
//                 }
//             } else if (original [i] >= 97 && original [i] <= 122) {
//                 original [i] += offset;
//                 if (original [i] > 122){
//                     original [i] -= 26;
//                 }
//             } else if (original [i] >= 48 && original [i] <= 57) {
//                 original [i] += offset;
//                 if (original [i] > 57){
//                     original [i] -= 10;
//                 }
//             }
//         }
//     }
// }
//
// void decrypt(char* encrypted, int offset){
//     if (offset >= 10) {
//         printf("Offset out of range.");
//     } else {
//         for (int i = 0; i < strlen(encrypted); i++) {
//             if (encrypted [i] >= 65 && encrypted [i] <= 90) {
//                 encrypted [i] -= offset;
//                 if (encrypted [i] < 65){
//                     encrypted [i] += 26;
//                 }
//             } else if (encrypted [i] >= 97 && encrypted [i] <= 122) {
//                 encrypted [i] -= offset;
//                 if (encrypted [i] < 97){
//                     encrypted [i] += 26;
//                 }
//             } else if (encrypted [i] >= 48 && encrypted [i] <= 57) {
//                 encrypted [i] -= offset;
//                 if (encrypted [i] < 48){
//                     encrypted [i] += 10;
//                 }
//             }
//         }
//     }
// }
//
// int main() {
//     printf("Input a string to encrypt, which must be less than 2018 characters: ");
//     char input[2048];
//     while(!(scanf("%[^\n]s", input) == 1 && strlen(input) <= 2048)){
//         printf("Invalid input, please try again: ");
//     }
//     encrypt(input, 3);
//     printf("Encrypted string: %s\n", input);
//     decrypt(input, 3);
//     printf("Decrypted string: %s\n", input);
//     return 0;
// }

// Chinese version

空 密(字* 明文, 整 移){
    如 (移 逾或為 10) {
        印("Offset out of range.");
    } 否 {
        遍 (整 所指 給 0; 所指 弗如 串長(明文); 所指之處盈一) {
            如 (明文 所指之物 逾或為 65 且 明文 所指之物 弗如或為 90) {
                明文 所指之物 自盈 移;
                如 (明文 所指之物 逾 90){
                    明文 所指之物 自損 26;
                }
            } 否 如 (明文 所指之物 逾或為 97 且 明文 所指之物 弗如或為 122) {
                明文 所指之物 自盈 移;
                如 (明文 所指之物 逾 122){
                    明文 所指之物 自損 26;
                }
            } 否 如 (明文 所指之物 逾或為 48 且 明文 所指之物 弗如或為 57) {
                明文 所指之物 自盈 移;
                如 (明文 所指之物 逾 57){
                    明文 所指之物 自損 10;
                }
            }
        }
    }
}

空 解(字* 密文, 整 移){
    如 (移 逾或為 10) {
        印("Offset out of range.");
    } 否 {
        遍 (整 所指 = 0; 所指 弗如 串長(密文); 所指之處盈一) {
            如 (密文 所指之物 逾或為 65 且 密文 所指之物 弗如或為 90) {
                密文 所指之物 自損 移;
                如 (密文 所指之物 弗如 65){
                    密文 所指之物 自盈 26;
                }
            } 否 如 (密文 所指之物 逾或為 97 且 密文 所指之物 弗如或為 122) {
                密文 所指之物 自損 移;
                如 (密文 所指之物 弗如 97){
                    密文 所指之物 自盈 26;
                }
            } 否 如 (密文 所指之物 逾或為 48 且 密文 所指之物 弗如或為 57) {
                密文 所指之物 自損 移;
                如 (密文 所指之物 弗如 48){
                    密文 所指之物 自盈 10;
                }
            }
        }
    }
}

整 概() {
    印("Input a string to encrypt, which must be less than 2018 characters: ");
    字 入串[2048];
    歪拗(非(得("%[^\n]s", 入串) 為 1 且 串長(入串) 弗如或為 2048)){
        印("Invalid input, please try again: ");
    }
    密(入串, 3);
    印("Encrypted string: %s\n", 入串);
    解(入串, 3);
    印("Decrypted string: %s\n", 入串);
    返 0;
}
