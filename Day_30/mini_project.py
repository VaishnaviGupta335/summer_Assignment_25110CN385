"""
=========================================================
   HOTEL MANAGEMENT SYSTEM  (Mini Project)
=========================================================
A console based Hotel Management System with two login
types - ADMIN and USER (customer/receptionist).

Data is stored in CSV files:
    staffdetails.csv     -> staff records
    roomdetails.csv      -> room records
    foodmenu.csv         -> food menu records
    customerdetails.csv  -> customer / booking records (auto-created)
    orders.csv           -> food order records        (auto-created)

Author : (your name here)
=========================================================
"""

import csv
import os
import sys
from datetime import datetime

# ---------------------------------------------------------------------------
# FILE PATHS  (all CSVs must be in the same folder as this script)
# ---------------------------------------------------------------------------
BASE_DIR = os.path.dirname(os.path.abspath(__file__))

STAFF_FILE = os.path.join(BASE_DIR, "staffdetails.csv")
ROOM_FILE = os.path.join(BASE_DIR, "roomdetails.csv")
FOOD_FILE = os.path.join(BASE_DIR, "foodmenu.csv")
CUSTOMER_FILE = os.path.join(BASE_DIR, "customerdetails.csv")
ORDER_FILE = os.path.join(BASE_DIR, "orders.csv")

# Field names for the two files this program creates on its own
CUSTOMER_FIELDS = ["Customer ID", "Name", "Phone", "Address",
                    "Room No", "Check-in", "Check-out", "Status"]
ORDER_FIELDS = ["Order ID", "Customer ID", "Food ID", "Food Name",
                "Quantity", "Total Price (₹)", "Date Time"]

# ---------------------------------------------------------------------------
# LOGIN CREDENTIALS  (change these as you like)
# ---------------------------------------------------------------------------
ADMIN_CREDENTIALS = {"admin": "admin123"}
USER_CREDENTIALS = {"user": "user123", "reception": "reception123"}


# ===========================================================================
#  GENERIC CSV HELPER FUNCTIONS
# ===========================================================================
def read_csv(filepath):
    """Return list of dict rows from a csv file. Empty list if file missing."""
    if not os.path.exists(filepath):
        return []
    with open(filepath, newline="", encoding="utf-8-sig") as f:
        return list(csv.DictReader(f))


def write_csv(filepath, rows, fieldnames):
    """Overwrite the csv file with the given rows."""
    with open(filepath, "w", newline="", encoding="utf-8-sig") as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)


def ensure_file(filepath, fieldnames):
    """Create the csv file with just a header if it does not already exist."""
    if not os.path.exists(filepath):
        write_csv(filepath, [], fieldnames)


def get_fieldnames(filepath, fallback):
    rows = read_csv(filepath)
    if rows:
        return list(rows[0].keys())
    return fallback


def print_table(rows, fieldnames):
    """Pretty print a list of dict rows as a simple table."""
    if not rows:
        print(" No records found.\n")
        return
    widths = {f: max(len(f), max((len(str(r.get(f, ""))) for r in rows), default=0)) for f in fieldnames}
    header = " | ".join(f.ljust(widths[f]) for f in fieldnames)
    print("-" * len(header))
    print(header)
    print("-" * len(header))
    for r in rows:
        print(" | ".join(str(r.get(f, "")).ljust(widths[f]) for f in fieldnames))
    print("-" * len(header))
    print()


def next_id(rows, id_field, prefix):
    """Generate the next sequential ID like S011, C005, F016, O003 ..."""
    max_num = 0
    for r in rows:
        val = str(r.get(id_field, ""))
        digits = "".join(ch for ch in val if ch.isdigit())
        if digits:
            max_num = max(max_num, int(digits))
    return f"{prefix}{max_num + 1:03d}"


def pause():
    input("\nPress Enter to continue...")


def get_nonempty(prompt):
    while True:
        val = input(prompt).strip()
        if val:
            return val
        print(" This field cannot be empty.")


def get_int(prompt):
    while True:
        val = input(prompt).strip()
        if val.isdigit():
            return int(val)
        print(" Please enter a valid number.")


# ===========================================================================
#  LOGIN
# ===========================================================================
def login(credentials, role_name):
    print(f"\n--- {role_name} LOGIN ---")
    for attempt in range(3):
        username = input("Username: ").strip()
        password = input("Password: ").strip()
        if credentials.get(username) == password:
            print(f"\n Login successful. Welcome, {username}!\n")
            return username
        else:
            print(f" Invalid credentials. Attempts left: {2 - attempt}")
    print("\n Too many failed attempts. Returning to main menu.\n")
    return None


# ===========================================================================
#  STAFF FUNCTIONS  (Admin only)
# ===========================================================================
def view_staff():
    print("\n===== STAFF DETAILS =====")
    rows = read_csv(STAFF_FILE)
    fieldnames = get_fieldnames(STAFF_FILE, ["Staff ID", "Name", "Department",
                                              "Designation", "Phone", "Shift", "Salary (₹)"])
    print_table(rows, fieldnames)


def add_staff():
    print("\n===== ADD NEW STAFF =====")
    rows = read_csv(STAFF_FILE)
    fieldnames = get_fieldnames(STAFF_FILE, ["Staff ID", "Name", "Department",
                                              "Designation", "Phone", "Shift", "Salary (₹)"])
    new_id = next_id(rows, "Staff ID", "S")
    name = get_nonempty("Name: ")
    department = get_nonempty("Department: ")
    designation = get_nonempty("Designation: ")
    phone = get_nonempty("Phone: ")
    shift = get_nonempty("Shift (Morning/Evening/Night/Day/General): ")
    salary = get_int("Salary (₹): ")

    new_row = {"Staff ID": new_id, "Name": name, "Department": department,
               "Designation": designation, "Phone": phone, "Shift": shift,
               "Salary (₹)": salary}
    rows.append(new_row)
    write_csv(STAFF_FILE, rows, fieldnames)
    print(f"\n Staff added successfully with ID: {new_id}")


def delete_staff():
    print("\n===== REMOVE STAFF =====")
    rows = read_csv(STAFF_FILE)
    fieldnames = get_fieldnames(STAFF_FILE, ["Staff ID", "Name", "Department",
                                              "Designation", "Phone", "Shift", "Salary (₹)"])
    print_table(rows, fieldnames)
    staff_id = get_nonempty("Enter Staff ID to remove: ").upper()
    new_rows = [r for r in rows if r.get("Staff ID", "").upper() != staff_id]
    if len(new_rows) == len(rows):
        print(" Staff ID not found.")
        return
    write_csv(STAFF_FILE, new_rows, fieldnames)
    print(f" Staff {staff_id} removed.")


def staff_menu():
    while True:
        print("""
        ----- STAFF MANAGEMENT -----
        1. View Staff Details
        2. Add Staff
        3. Remove Staff
        4. Back to Admin Menu
        """)
        choice = input("Enter choice: ").strip()
        if choice == "1":
            view_staff()
        elif choice == "2":
            add_staff()
        elif choice == "3":
            delete_staff()
        elif choice == "4":
            break
        else:
            print(" Invalid choice.")
        pause()


# ===========================================================================
#  ROOM FUNCTIONS
# ===========================================================================
def view_rooms(only_available=False):
    print("\n===== ROOM DETAILS =====")
    rows = read_csv(ROOM_FILE)
    fieldnames = get_fieldnames(ROOM_FILE, ["Room No", "Room Type", "Floor", "Capacity",
                                             "AC", "Price/Day (₹)", "Status", "Customer ID"])
    if only_available:
        rows = [r for r in rows if r.get("Status", "").strip().lower() == "available"]
    print_table(rows, fieldnames)
    return rows


def add_room():
    print("\n===== ADD NEW ROOM =====")
    rows = read_csv(ROOM_FILE)
    fieldnames = get_fieldnames(ROOM_FILE, ["Room No", "Room Type", "Floor", "Capacity",
                                             "AC", "Price/Day (₹)", "Status", "Customer ID"])
    room_no = get_nonempty("Room No: ")
    if any(r.get("Room No") == room_no for r in rows):
        print(" A room with this number already exists.")
        return
    room_type = get_nonempty("Room Type (Standard/Deluxe/Luxury/Suite/Executive): ")
    floor = get_int("Floor: ")
    capacity = get_int("Capacity: ")
    ac = get_nonempty("AC (Yes/No): ")
    price = get_int("Price/Day (₹): ")

    new_row = {"Room No": room_no, "Room Type": room_type, "Floor": floor,
               "Capacity": capacity, "AC": ac, "Price/Day (₹)": price,
               "Status": "Available", "Customer ID": "-"}
    rows.append(new_row)
    write_csv(ROOM_FILE, rows, fieldnames)
    print(f" Room {room_no} added successfully.")


def update_room_status():
    print("\n===== UPDATE ROOM STATUS =====")
    rows = read_csv(ROOM_FILE)
    fieldnames = get_fieldnames(ROOM_FILE, ["Room No", "Room Type", "Floor", "Capacity",
                                             "AC", "Price/Day (₹)", "Status", "Customer ID"])
    print_table(rows, fieldnames)
    room_no = get_nonempty("Enter Room No to update: ")
    for r in rows:
        if r.get("Room No") == room_no:
            new_status = get_nonempty("New Status (Available/Booked/Maintenance): ")
            r["Status"] = new_status
            if new_status.lower() != "booked":
                r["Customer ID"] = "-"
            write_csv(ROOM_FILE, rows, fieldnames)
            print(f" Room {room_no} status updated to {new_status}.")
            return
    print(" Room not found.")


def room_menu():
    while True:
        print("""
        ----- ROOM MANAGEMENT -----
        1. View All Rooms
        2. View Available Rooms
        3. Add New Room
        4. Update Room Status
        5. Back to Admin Menu
        """)
        choice = input("Enter choice: ").strip()
        if choice == "1":
            view_rooms()
        elif choice == "2":
            view_rooms(only_available=True)
        elif choice == "3":
            add_room()
        elif choice == "4":
            update_room_status()
        elif choice == "5":
            break
        else:
            print(" Invalid choice.")
        pause()


# ===========================================================================
#  FOOD MENU FUNCTIONS
# ===========================================================================
def view_food_menu(only_available=False):
    print("\n===== FOOD MENU =====")
    rows = read_csv(FOOD_FILE)
    fieldnames = get_fieldnames(FOOD_FILE, ["Food ID", "Food Name", "Category",
                                             "Price (₹)", "Available", "Preparation Time (min)"])
    if only_available:
        rows = [r for r in rows if r.get("Available", "").strip().lower() == "yes"]
    print_table(rows, fieldnames)
    return rows


def add_food_item():
    print("\n===== ADD FOOD ITEM =====")
    rows = read_csv(FOOD_FILE)
    fieldnames = get_fieldnames(FOOD_FILE, ["Food ID", "Food Name", "Category",
                                             "Price (₹)", "Available", "Preparation Time (min)"])
    new_id = next_id(rows, "Food ID", "F")
    name = get_nonempty("Food Name: ")
    category = get_nonempty("Category (Main Course/Bread/Dessert/Beverage/etc): ")
    price = get_int("Price (₹): ")
    available = get_nonempty("Available (Yes/No): ")
    prep_time = get_int("Preparation Time (min): ")

    new_row = {"Food ID": new_id, "Food Name": name, "Category": category,
               "Price (₹)": price, "Available": available,
               "Preparation Time (min)": prep_time}
    rows.append(new_row)
    write_csv(FOOD_FILE, rows, fieldnames)
    print(f" Food item added successfully with ID: {new_id}")


def remove_food_item():
    print("\n===== REMOVE FOOD ITEM =====")
    rows = read_csv(FOOD_FILE)
    fieldnames = get_fieldnames(FOOD_FILE, ["Food ID", "Food Name", "Category",
                                             "Price (₹)", "Available", "Preparation Time (min)"])
    print_table(rows, fieldnames)
    food_id = get_nonempty("Enter Food ID to remove: ").upper()
    new_rows = [r for r in rows if r.get("Food ID", "").upper() != food_id]
    if len(new_rows) == len(rows):
        print(" Food ID not found.")
        return
    write_csv(FOOD_FILE, new_rows, fieldnames)
    print(f" Food item {food_id} removed.")


def food_menu_admin():
    while True:
        print("""
        ----- FOOD MENU MANAGEMENT -----
        1. View Food Menu
        2. Add Food Item
        3. Remove Food Item
        4. Back to Admin Menu
        """)
        choice = input("Enter choice: ").strip()
        if choice == "1":
            view_food_menu()
        elif choice == "2":
            add_food_item()
        elif choice == "3":
            remove_food_item()
        elif choice == "4":
            break
        else:
            print(" Invalid choice.")
        pause()


# ===========================================================================
#  CUSTOMER FUNCTIONS
# ===========================================================================
def view_customers():
    print("\n===== CUSTOMER DETAILS =====")
    rows = read_csv(CUSTOMER_FILE)
    print_table(rows, CUSTOMER_FIELDS)


def book_room():
    print("\n===== BOOK A ROOM =====")
    available_rooms = view_rooms(only_available=True)
    if not available_rooms:
        print(" No rooms available right now.")
        return

    room_no = get_nonempty("Enter Room No to book: ")
    room_rows = read_csv(ROOM_FILE)
    room_fieldnames = get_fieldnames(ROOM_FILE, ["Room No", "Room Type", "Floor", "Capacity",
                                                  "AC", "Price/Day (₹)", "Status", "Customer ID"])
    target_room = None
    for r in room_rows:
        if r.get("Room No") == room_no and r.get("Status", "").lower() == "available":
            target_room = r
            break
    if not target_room:
        print(" Invalid room number or room not available.")
        return

    customers = read_csv(CUSTOMER_FILE)
    new_id = next_id(customers, "Customer ID", "C")
    name = get_nonempty("Customer Name: ")
    phone = get_nonempty("Phone: ")
    address = get_nonempty("Address: ")
    checkin = datetime.now().strftime("%Y-%m-%d")
    checkout = get_nonempty("Expected Check-out Date (YYYY-MM-DD): ")

    new_customer = {"Customer ID": new_id, "Name": name, "Phone": phone,
                     "Address": address, "Room No": room_no,
                     "Check-in": checkin, "Check-out": checkout, "Status": "Checked-in"}
    customers.append(new_customer)
    write_csv(CUSTOMER_FILE, customers, CUSTOMER_FIELDS)

    # update room status
    target_room["Status"] = "Booked"
    target_room["Customer ID"] = new_id
    write_csv(ROOM_FILE, room_rows, room_fieldnames)

    print(f"\n Room {room_no} booked successfully for {name}.")
    print(f" Customer ID: {new_id}  (please remember this for food orders / checkout)")


def checkout_room():
    print("\n===== CHECKOUT / CANCEL BOOKING =====")
    customer_id = get_nonempty("Enter your Customer ID: ").upper()
    customers = read_csv(CUSTOMER_FILE)
    target_customer = None
    for c in customers:
        if c.get("Customer ID", "").upper() == customer_id and c.get("Status") == "Checked-in":
            target_customer = c
            break
    if not target_customer:
        print(" No active booking found for this Customer ID.")
        return

    room_no = target_customer["Room No"]
    room_rows = read_csv(ROOM_FILE)
    room_fieldnames = get_fieldnames(ROOM_FILE, ["Room No", "Room Type", "Floor", "Capacity",
                                                  "AC", "Price/Day (₹)", "Status", "Customer ID"])
    for r in room_rows:
        if r.get("Room No") == room_no:
            r["Status"] = "Available"
            r["Customer ID"] = "-"
    write_csv(ROOM_FILE, room_rows, room_fieldnames)

    target_customer["Status"] = "Checked-out"
    write_csv(CUSTOMER_FILE, customers, CUSTOMER_FIELDS)
    print(f" Customer {customer_id} checked out. Room {room_no} is now available.")


# ===========================================================================
#  FOOD ORDER FUNCTIONS
# ===========================================================================
def order_food():
    print("\n===== ORDER FOOD =====")
    menu = view_food_menu(only_available=True)
    if not menu:
        print(" No food items available right now.")
        return

    customer_id = get_nonempty("Enter your Customer ID: ").upper()
    customers = read_csv(CUSTOMER_FILE)
    if not any(c.get("Customer ID", "").upper() == customer_id for c in customers):
        print(" Customer ID not found. Please book a room first or check your ID.")
        return

    food_id = get_nonempty("Enter Food ID to order: ").upper()
    food_item = next((f for f in menu if f.get("Food ID", "").upper() == food_id), None)
    if not food_item:
        print(" Invalid Food ID or item not available.")
        return

    qty = get_int("Quantity: ")
    price = float(food_item.get("Price (₹)", 0))
    total = price * qty

    orders = read_csv(ORDER_FILE)
    new_order_id = next_id(orders, "Order ID", "O")
    new_order = {"Order ID": new_order_id, "Customer ID": customer_id,
                 "Food ID": food_item["Food ID"], "Food Name": food_item["Food Name"],
                 "Quantity": qty, "Total Price (₹)": total,
                 "Date Time": datetime.now().strftime("%Y-%m-%d %H:%M")}
    orders.append(new_order)
    write_csv(ORDER_FILE, orders, ORDER_FIELDS)

    print(f"\n Order placed! Order ID: {new_order_id}")
    print(f" {qty} x {food_item['Food Name']} = ₹{total}")


def view_my_orders():
    print("\n===== MY ORDERS =====")
    customer_id = get_nonempty("Enter your Customer ID: ").upper()
    orders = read_csv(ORDER_FILE)
    my_orders = [o for o in orders if o.get("Customer ID", "").upper() == customer_id]
    print_table(my_orders, ORDER_FIELDS)


def view_all_orders():
    print("\n===== ALL FOOD ORDERS =====")
    orders = read_csv(ORDER_FILE)
    print_table(orders, ORDER_FIELDS)


# ===========================================================================
#  ADMIN MENU
# ===========================================================================
def admin_menu():
    while True:
        print("""
        ================ ADMIN MENU ================
        1. Staff Management
        2. Room Management
        3. Food Menu Management
        4. View Customer Details
        5. View All Food Orders
        6. Logout
        ==============================================
        """)
        choice = input("Enter choice: ").strip()
        if choice == "1":
            staff_menu()
        elif choice == "2":
            room_menu()
        elif choice == "3":
            food_menu_admin()
        elif choice == "4":
            view_customers()
            pause()
        elif choice == "5":
            view_all_orders()
            pause()
        elif choice == "6":
            print("\n Logged out from Admin.\n")
            break
        else:
            print(" Invalid choice.")


# ===========================================================================
#  USER MENU  (customer / receptionist facing)
# ===========================================================================
def user_menu():
    while True:
        print("""
        ================ USER MENU ================
        1. View Available Rooms
        2. Book a Room
        3. Checkout / Cancel Booking
        4. View Food Menu
        5. Order Food
        6. View My Food Orders
        7. Logout
        =============================================
        """)
        choice = input("Enter choice: ").strip()
        if choice == "1":
            view_rooms(only_available=True)
        elif choice == "2":
            book_room()
        elif choice == "3":
            checkout_room()
        elif choice == "4":
            view_food_menu()
        elif choice == "5":
            order_food()
        elif choice == "6":
            view_my_orders()
        elif choice == "7":
            print("\n Logged out from User.\n")
            break
        else:
            print(" Invalid choice.")
        pause()


# ===========================================================================
#  MAIN PROGRAM
# ===========================================================================
def main():
    # make sure the auto-generated files exist
    ensure_file(CUSTOMER_FILE, CUSTOMER_FIELDS)
    ensure_file(ORDER_FILE, ORDER_FIELDS)

    while True:
        print("""
        ##################################################
        #        HOTEL MANAGEMENT SYSTEM                 #
        ##################################################
        1. Admin Login
        2. User Login
        3. Exit
        """)
        choice = input("Enter choice: ").strip()

        if choice == "1":
            user = login(ADMIN_CREDENTIALS, "ADMIN")
            if user:
                admin_menu()
        elif choice == "2":
            user = login(USER_CREDENTIALS, "USER")
            if user:
                user_menu()
        elif choice == "3":
            print("\n Thank you for using Hotel Management System. Goodbye!\n")
            sys.exit(0)
        else:
            print(" Invalid choice, please try again.")


if __name__ == "__main__":
    main()