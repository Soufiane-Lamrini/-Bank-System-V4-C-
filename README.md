# 🏦 Bank System V4 (C++)

📘 **OOP as It Should Be – Applications**
*From understanding concepts to professional practice*

This project represents the culmination of my C++ programming journey and demonstrates the practical application of Object-Oriented Programming (OOP) principles. It follows my learning roadmap after mastering foundations, algorithms, and OOP concepts.


## 🗝️ About

This banking system is **100% object-oriented** and showcases how OOP can be used to build complete, professional applications. It includes customer management, user management, currency handling, and transaction tracking with a **modular and scalable architecture**.

---

## ✨ Core Features

* 👤 **Customer Management**: Add, update, delete, search, and list customers.
* 🔑 **User Management**: Create, authenticate, and manage roles and permissions.
* 💰 **Banking Operations**: Deposit, withdrawal, transfer, and balance calculation.
* 🌍 **Currency Module**: Currency listing, exchange rate updates, and conversion calculator.
* 📊 **Transactions**: Logging and tracking of all transfers.
* 🖥️ **Modular Interface**: Over 25 independent screens for better organization.

---

## 🧱 Object-Oriented Architecture

The project is designed following **OOP principles**:

* **Encapsulation**: Each class manages its own data and behavior (`clsBankClient`, `clsUser`, `clsCurrency`, etc.).
* **Abstraction**: Clear interfaces for entity interaction.
* **Inheritance**: Reuse of common behaviors (`clsPerson` as a base class).
* **Polymorphism**: Context-adapted methods.

---

## 📂 Project Structure

```
BankSystemV3/
├── Core/
│   ├── clsBankClient.h
│   ├── clsCurrency.h
│   ├── clsPerson.h
│   ├── clsUser.h
│   └── ...
├── Lib/
│   ├── clsDate.h
│   ├── clsInputValidation.h
│   ├── clsString.h
│   └── clsUtility.h
├── Screens/
│   ├── clsMainScreen.h
│   ├── clsLoginScreen.h
│   ├── clsClientListScreen.h
│   ├── clsTransactionsScreen.h
│   ├── clsCurrencyCalculator.h
│   ├── clsUpdateClientScreen.h
│   ├── clsUsersListScreen.h
│   └── ...
├── Bank System.cpp
└── README.md
```

---

## 📖 Learning Roadmap

This project is the **11th course** in my learning path, following:

1. Programming Foundations – Level 1
2. Algorithms & Problem Solving – Level 1
3. Introduction to Programming with C++ – Level 1
4. Algorithms & Problem Solving – Level 1 (Clean Code Solutions)
5. Algorithms & Problem Solving – Level 2
6. Introduction to Programming Using C++ – Level 2
7. Algorithms & Problem Solving – Level 3
8. Algorithms & Problem Solving – Level 4
9. Foundations – Level 2
10. OOP as It Should Be – Concepts

---

## ⚙️ Installation & Execution

**Clone the repository:**

```bash
git clone https://github.com/your-username/BankSystemV4.git
```

**Navigate to the project folder:**

```bash
cd BankSystemV4
```

**Compile and run** (examples):

* Using **g++** (Linux / MinGW):

```bash
g++ -std=c++17 "Bank System.cpp" -o BankSystemV4 && ./BankSystemV4
```

* In **Visual Studio**: Open the project/single-file, set C++ standard (C++17 or higher), then build & run.

> Replace `your-username` with your GitHub username in the clone URL.

---

## 🛠️ Usage & Examples

* Log in as an admin user (if a default admin exists) and navigate the menu: **Clients**, **Users**, **Transactions**, **Currencies**.
* Example commands in the console menu: Add client → Update client → Make a transfer → View history.

---

## 🧪 Testing

The repository contains modules that can be tested manually via the console interface. For future enhancements: integrate a unit test suite (Catch2 / GoogleTest) to validate core classes (`clsBankClient`, `clsCurrency`, `clsUser`).

---

## 🎓 Skills Acquired

* Building real-world applications with OOP
* Structuring complex codebases with confidence
* Extending systems safely and cleanly
* Reading and understanding professional OOP projects

---

## 🤝 Contribution

Contributions are welcome!

1. Fork the project
2. Create a branch (`feature/my-feature`)
3. Commit your changes
4. Open a Pull Request

Please open an issue before starting a major feature.


---

## 📜 License

This project is licensed under the **MIT License**. See the `LICENSE` file.

---

## 👨‍💻 Author

**Soufiane Lamrini**
Passionate about C++, software architecture.

---

## 👨‍🏫 Acknowledgements

Special thanks to **Dr. Mohamed Abu-Hadhoud**, my trainer and mentor, for his guidance and expertise.
