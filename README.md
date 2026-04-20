

https://github.com/user-attachments/assets/f68a8625-62ea-400e-9a3b-0b98b0dab196

# Process-Synchronisation--OS-project
This project is following with Operating System course project. The problem is about Process synchronisation using mutex and semaphore. 

# 🌙⭐ Moon & Star Dream Synchronization (OS Concurrency Project)

## 📌 Project Overview

This project demonstrates the concept of **process synchronization, mutual exclusion, and inter-thread communication** using a creative real-world inspired scenario.

In a magical setting, two entities — **Moon** and **Star** — attempt to synchronize their sleep cycles so they can meet in their dreams at the mystical **Dream Park**. Their coordination is managed using:

- **Semaphore (SleepToMeet)** → Controls synchronization between threads  
- **Mutex Lock** → Prevents race conditions during shared state updates  
- **Multithreading (Pthreads)** → Simulates concurrent execution of processes  
- **Observer Thread (Whisper)** → Monitors system state and coordinates communication  

This project is implemented in **C using POSIX threads (pthreads)** and demonstrates key Operating System concepts in a practical and visual way.

---

## 🎯 Problem Statement

> “I sleep so that we can meet.”

In a magical town, two lovebirds — Moon and Star — try to synchronize their naps to meet in their dreams at the enchanting **Dream Park**. The park only activates when both are asleep simultaneously.

To manage this, they use:

- A semaphore called **SleepToMeet**
- A mutex lock to avoid race conditions
- A helper thread named **Whisper**

Each character runs as a separate thread. The system ensures that they can only "meet" when both are asleep at the same time, while Whisper coordinates and monitors their state.

---
🎬 Project Output

The following video demonstrates the execution of the Moon & Star Dream Synchronization System, showcasing thread coordination, semaphore signaling, and mutex-controlled state updates.

📽️ Output Demo:

👉 https://github.com/user-attachments/assets/13b2588d-f3dd-498a-9bba-e662277a9db3

## ⚙️ System Design

### 🧵 Threads Used
- `moon_thread` → Represents Moon’s sleep cycle
- `star_thread` → Represents Star’s sleep cycle
- `whisper_thread` → Monitors and synchronizes both states

---

### 🔐 Synchronization Tools
- **Semaphore (`SleepToMeet`)**
  - Used to signal state changes between threads

- **Mutex Lock**
  - Ensures only one thread modifies shared variables at a time

---

### 🧠 Shared Variables
- `MoonAsleep` → Indicates Moon’s sleep state
- `StarAsleep` → Indicates Star’s sleep state

---

## 🧪 How It Works

1. Moon and Star independently update their sleep status.
2. Each update signals the semaphore.
3. Whisper thread waits for signals.
4. When both Moon and Star are asleep:
   - They “meet” in Dream Park
5. If only one is asleep:
   - Whisper waits or notifies accordingly

---

## 💻 Technologies Used

- C Programming Language
- POSIX Threads (pthread library)
- Semaphores
- Mutex Locks
- Linux/Unix Environment

---

## 🚀 How to Run

### 🔧 Compile
```bash
gcc main.c -o dream -pthread
./dream

###🧩 Project Architecture

        +------------------+
        |  Moon Thread     |
        +------------------+
                  |
                  v
        +------------------+
        | SleepToMeet      |  (Semaphore)
        +------------------+
                  |
                  v
        +------------------+
        | Whisper Thread   |
        +------------------+
                  ^
                  |
        +------------------+
        |  Star Thread     |
        +------------------+

     Shared Resource Protection
            (Mutex Lock)


📊 Key Learning Outcomes
Understanding process synchronization
Implementing semaphores in real scenarios
Using mutex locks to prevent race conditions
Working with multithreaded programming in C
Designing OS concepts through creative simulation

