# C-Krypt 🔐
A lightweight, secure Password Vault written in C.

## 🚀 Features
- **Secure Storage**: Uses a binary file (`vault.dat`) to store credentials.
- **XOR Encryption**: Implements symmetric bitwise XOR encryption to scramble passwords.
- **Case-Insensitive Search**: Easily find your credentials regardless of capitalization.
- **Efficient Data Handling**: Uses structs and direct file I/O for speed.

## 🛠️ How it Works
### Encryption Logic
C-Krypt uses a symmetric encryption algorithm. The password is XORed with a `SECRET_KEY` before being saved. To retrieve it, the same key is applied to reverse the process.

$$Data \oplus Key = EncryptedData$$
$$EncryptedData \oplus Key = Data$$

## 📂 Project Structure
- `main.c`: Contains the core logic and encryption engine.
- `C-Krypt.cbp`: Code::Blocks project file.
- `.gitignore`: Ensures binary junk like `/bin` and `/obj` stay out of the repo.

## ⚙️ How to Run
1. Open the project in **Code::Blocks**.
2. Build and Run (`F9`).
3. Add your passwords and keep them safe!

---
*Created as part of a C Programming Project.*