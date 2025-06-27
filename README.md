# Hotel Management and Booking System (C++ | Windows)

This is a simple console-based Hotel Management System written in **C++**, intended for **Windows** systems using `conio.h`. It allows basic hotel operations such as room management, customer check-in/check-out, and room availability tracking.

---

## 🧩 Features

- ✅ Add, edit, or delete rooms  
- ✅ Check-in a customer with booking details  
- ✅ Check-out and generate a bill  
- ✅ View available rooms  
- ✅ Search for a customer by name  
- ✅ Guest summary report  

---

## 🛠️ Requirements

- **Operating System**: Windows (required due to `conio.h`)
- **Compiler**: [MinGW](https://www.mingw-w64.org/) or MSVC (Visual Studio C++)

---

## 🔄 How to Compile & Run (Windows)

### ✅ Using Command Line (MinGW)

1. Open `CMD` or `PowerShell`.
2. Navigate to the folder containing `Hotel_ms.cpp`.

```bash
g++ Hotel_ms.cpp -o hotel
hotel.exe
```

> Make sure `g++` is added to your system's PATH.

### ✅ Using Code::Blocks

1. Open Code::Blocks.
2. Create a new project → Console Application (C++).
3. Replace the `main.cpp` with `Hotel_ms.cpp` content.
4. Build and run the project.

---

## 📁 File Structure

```
Hotel-Management-and-Booking-System/
├── Hotel_ms.cpp        # Main source code (Windows-only)
├── README.md           # Documentation
```

---

## ⚠️ Notes

- This version uses `conio.h` (for `getch()` and `cls`), so **it won't work on Linux/Mac**.
- For a **Linux-compatible version**, you can request a `conio.h`-free version of this code.

---

## 📸 Sample Output

```text
        Hotel Management System
        ------------------------
        1. Manage Room
        2. Check-In room
        3. Available Room
        4. Check-Out Room
        5. Search Customer
        6. Guest Summary
        7. Exit
        ------------------------
        Enter your choice:
```

---

## 🙋‍♂️ Author

Mamidipelli Krishna Hasini  
*Hotel Management System Project (Console-based, C++)*

---

## 📜 License

This project is for educational use. No license enforced.
