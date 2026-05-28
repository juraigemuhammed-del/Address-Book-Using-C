📒 Address Book Management System (C Project)

A simple and modular Address Book Management System written in C, designed to store, search, edit, delete, and sort contacts. All contact data is stored permanently in a CSV file.

🚀 Features ✔️ Create Contact

Add a new contact with:

Name

Phone Number

Email

🔍 Search Contact

Search by:

Name

Phone Number

Email

✏️ Edit Contact

Modify any existing contact details.

🗑️ Delete Contact

Remove a contact from the system.

💾 Save Contacts

All data is saved in contacts.csv.

📜 List Contacts

View all contacts with sorting options:

Sort by Name

Sort by Phone Number

Sort by Email

🔄 Persistent Storage

Contacts remain saved even after restarting the program (CSV-based storage).

📂 File Structure

Your project contains the following files:

a.out contact.c contact.h contacts.csv file.c file.h main.c populate.c populate.h strings.c

🛠️ Modules Overview

main.c → Entry point, menu handling

contact.c / contact.h → Contact creation, editing, deleting

strings.c → Custom string-handling utilities

file.c / file.h → File reading/writing (CSV operations)

populate.c / populate.h → Load contacts from CSV into memory

⚙️ Compilation

Use this command to compile the entire project:

gcc *.c

▶️ How to Run

After compilation, run the program using:

./a.out

📤 Contact Storage Format (contacts.csv)

Example:

Name,Phone,Email John Doe,9876543210,john@example.com Alice,9123456789,alice@example.com

📘 Optional Future Improvements

Export as JSON

Import CSV from external sources

GUI-based version
