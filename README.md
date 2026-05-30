## Project Description

The **Academic Grading & Management System** is a lightweight, secure command-line application engineered in C++ to simulate a modern academic portal. Designed with standard university workflows in mind, the system completely replaces live databases with persistent data storage managed entirely through native C++ file streams (`std::fstream`). 

The application utilizes object-oriented programming principles to strictly enforce secure, role-based access control, offering customized functionalities for two primary user groups:

### Key Features

*   **For Instructors (Faculty Portal):**
    *   **Course & Content Creation:** Publish original assignments, manage course syllabi, and set evaluation parameters.
    *   **Grade Book Management:** Review student assignment submissions, modify academic records dynamically, and calculate total grade averages securely.
    
*   **For Students (Student Portal):**
    *   **Course Registration:** Browse active course catalogs and dynamically register for available classes.
    *   **Assignment Hub:** View real-time assignment postings and directly upload/submit solutions to the system.
    *   **Academic Transcripts:** Safely pull and view up-to-date personal grade reports, transcripts, and course performance analytics.

### Technical Implementation

*   **Persistence Layer:** Built entirely on text file parsing, rewriting, and structured data serialization using native C++ File I/O logic.
*   **Data Structures:** Leverages efficient in-memory data management paradigms to read database states, execute lookups, and safely commit system updates back to disk.
*   **Role-Based Security:** Features a robust authentication filter that separates UI menus and restricts file modification permissions based on the logged-in user type.
