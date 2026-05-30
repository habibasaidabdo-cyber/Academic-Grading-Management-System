# Academic Grading & Management System 🏫

A robust, multi-role university management portal engineered in C++. This application bypasses complex relational databases by utilizing native C++ File I/O serialization to persistently store and process live student-faculty logs.

---

## 📂 Repository Architecture

Click on the sections below to explore the internal module structures of the application:

<details>
<summary><b>💻 Source Files (.cpp)</b></summary>

* **`main.cpp`** & **`mainmenu.cpp`** — System entry point and master navigation workflow control.
* **`doctor.cpp`** & **`doctorflowapp.cpp`** — Core mechanics for the Faculty Portal experience.
* **`student.cpp`** & **`studentflowapp.cpp`** — Student account actions and validation logic.
* **`course.cpp`** — Handles runtime course tracking matrices.
* **`assignment.cpp`** & **`assignmentsolution.cpp`** — Task creation and submission processing models.
* **`dataloader.cpp`** & **`downloadingdata.cpp`** — File-to-memory stream handlers.
</details>

<details>
<summary><b>📋 Header Files (.h)</b></summary>

* **`mainmenu.h`**
* **`doctor.h`** & **`doctorflowapp.h`**
* **`student.h`** & **`studentflowapp.h`**
* **`course.h`**
* **`assignment.h`** & **`assignmentsolution.h`**
* **`dataloader.h`** & **`downloadingdata.h`**
</details>

<details>
<summary><b>🗃️ Resource Files (.txt)</b></summary>

* **`student.txt`** — Holds student profile data.
* **`doctor.txt`** — Securely references faculty access records.
* **`course.txt`** — Houses cataloged course parameters.
* **`registerd.txt`** — Tracks student enrollment mappings.
* **`assignment.txt`** — Stores instructor assignment specs.
* **`assignmentsolution.txt`** — Logs secure submission locations.
</details>

---

## 🚀 Key Features

* **Faculty Command Center:** Instructors can publish custom tasks, track course rosters, and dynamically apply persistent grades.
* **Student Roster Portal:** Students can browse available courses, register for open rosters, submit assignments, and review live transcripts.
* **Persistent File I/O Layer:** Implements sequential text-parsing and tokenizing strategies using `<fstream>` channels to prevent volatile system data loss.

---

## ⚡ Getting Started

### Prerequisites
Make sure you have a modern C++ compiler installed (GCC/G++ or Clang) supporting **C++11 or higher**.

### Compilation & Execution
```bash
# Clone the repository
git clone [https://github.com/habibasaidabdo-cyber/Academic-Grading-Management-System.git](https://github.com/habibasaidabdo-cyber/Academic-Grading-Management-System.git)

# Move into the project root directory
cd Academic-Grading-Management-System

# Move into the inner system folder where source files live
cd system

# Compile the source code using G++
g++ -std=c++11 main.cpp mainmenu.cpp doctor.cpp doctorflowapp.cpp student.cpp studentflowapp.cpp course.cpp assignment.cpp assignmentsolution.cpp dataloader.cpp downloadingdata.cpp -o AcademicPortal

# Launch the system interface
./AcademicPortal
