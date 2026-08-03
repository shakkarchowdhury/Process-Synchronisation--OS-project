# 🌙 I Sleep So That We Can Meet

### An Operating Systems Process Synchronization Project using POSIX Threads, Mutex, and Semaphores

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS-success)
![Threads](https://img.shields.io/badge/POSIX-Pthreads-orange)
![Synchronization](https://img.shields.io/badge/Synchronization-Semaphores%20%26%20Mutexes-red)
![License](https://img.shields.io/badge/License-MIT-green)

---

## 📖 Overview

**"I Sleep So That We Can Meet"** is a creative Operating Systems project that demonstrates **process/thread synchronization** using **POSIX Threads (`pthread`)**, **Mutex Locks**, and **Semaphores**.

The project tells the story of two independent threads:

* 🌙 **Moon**
* ⭐ **Star**

Each thread sleeps independently. A third thread, **🦉 Whisper**, continuously monitors both states. Only when **both Moon and Star are asleep at the same time** can they finally meet in the **Dream Park**.

This simple story models a classic synchronization problem where multiple threads coordinate through shared resources.

---

## ✨ Features

* 🧵 Multi-threaded implementation using POSIX Threads
* 🔒 Thread-safe shared variables with Mutex
* 🚦 Event synchronization using Semaphores
* 💡 Demonstrates inter-thread communication
* 🌙 Creative simulation instead of a traditional synchronization example
* 📚 Easy to understand for Operating Systems learners

---

## 🏗️ Project Structure

```text
.
├── README.md
└── I_sleeep_so_that_we_can_meet.c
```

---

## ⚙️ Technologies Used

* C Programming Language
* POSIX Threads (pthread)
* POSIX Semaphores
* Mutex Locks
* Linux/macOS Terminal

---

## 🔄 Synchronization Flow

```text
Moon Thread
      │
      ▼
 Moon falls asleep
      │
      ▼
Semaphore Signal
      │
      ▼
      🦉 Whisper
      ▲
      │
Semaphore Signal
      │
      ▼
 Star falls asleep
      │
      ▼
Both Sleeping?
      │
     Yes
      ▼
🌙 + ⭐ Meet in Dream Park 💫
```

---

## ▶️ Compilation

```bash
gcc I_sleeep_so_that_we_can_meet.c -o dream -lpthread
```

---

## ▶️ Run

```bash
./dream
```

---

## 💻 Sample Output

```text
🌙 Moon is asleep
🦉 Whisper: Moon is asleep, waiting for Star ⭐

⭐ Star is asleep
🦉 Whisper: Both Moon and Star are asleep!
They meet in Dream Park 💫

🌙 Moon is asleep
🦉 Whisper: Moon is asleep, waiting for Star ⭐

⭐ Star is asleep
🦉 Whisper: Both Moon and Star are asleep!
They meet in Dream Park 💫
```

---

## 🧠 Operating System Concepts Demonstrated

* Process Synchronization
* Multithreading
* Race Condition Prevention
* Critical Section Protection
* Mutual Exclusion
* Semaphore Signaling
* Thread Coordination
* Shared Memory Synchronization

---

## 🎯 Learning Objectives

This project helps learners understand:

* How multiple threads execute concurrently
* Why synchronization is necessary
* How semaphores notify waiting threads
* How mutexes protect shared resources
* How monitors coordinate independent execution

---

## 🚀 Future Improvements

* Add multiple Moon and Star threads
* Visual terminal animation
* Random sleep intervals
* Thread termination handling
* Logging system
* GUI visualization using SDL or OpenGL

---

## 👨‍💻 Author

**Shakkar Chowdhury**

Computer Science & Engineering Student

---

## ⭐ If you like this project

Give this repository a ⭐ on GitHub and feel free to fork it for your own Operating Systems experiments.
