
import java.util.Scanner;

class Employee {
    String name, department, designation;
    int employeeId, salary;
    Employee next, prev;

    public void accept(Scanner scanner) {
        System.out.print("Enter name: ");
        name = scanner.next();
        System.out.print("Enter department: ");
        department = scanner.next();
        System.out.print("Enter designation: ");
        designation = scanner.next();
        System.out.print("Enter employee ID: ");
        employeeId = scanner.nextInt();
        System.out.print("Enter salary: ");
        salary = scanner.nextInt();
    }

    public void display() {
        System.out.println("Name: " + name);
        System.out.println("Department: " + department);
        System.out.println("Designation: " + designation);
        System.out.println("Employee ID: " + employeeId);
        System.out.println("Salary: " + salary);
    }
}

public class Main {
    static Employee start = null, tail = null, temp = null, newnode = null;
    static Scanner scanner = new Scanner(System.in);

    public static void addEmployee() {
        newnode = new Employee();
        newnode.accept(scanner);
        newnode.next = null;
        newnode.prev = null;

        if (start == null) {
            start = tail = newnode;
            newnode.next = start;
            newnode.prev = start;
        } else {
            temp = start;
            while (temp.next != start) {
                temp = temp.next;
            }
            temp.next = newnode;
            newnode.prev = temp;
            newnode.next = start;
            start.prev = newnode;
            tail = newnode;
        }
    }

    public static void displayAscending() {
        temp = start;
        do {
            temp.display();
            System.out.println();
            temp = temp.next;
        } while (temp != start);
    }

    public static void displayDescending() {
        temp = tail;
        do {
            temp.display();
            System.out.println();
            temp = temp.prev;
        } while (temp != tail);
    }

    public static void searchEmployee(int employeeId) {
        temp = start;
        do {
            if (temp.employeeId == employeeId) {
                temp.display();
                return;
            }
            temp = temp.next;
        } while (temp != start);
        System.out.println("Employee not found.");
    }

    public static void updateEmployee(int employeeId) {
        temp = start;
        do {
            if (temp.employeeId == employeeId) {
                System.out.print("Enter new name: ");
                temp.name = scanner.next();
                System.out.print("Enter new department: ");
                temp.department = scanner.next();
                System.out.print("Enter new designation: ");
                temp.designation = scanner.next();
                System.out.print("Enter new employee ID: ");
                temp.employeeId = scanner.nextInt();
                System.out.print("Enter new salary: ");
                temp.salary = scanner.nextInt();
                return;
            }
            temp = temp.next;
        } while (temp != start);
        System.out.println("Employee not found.");
    }

    public static void countEmployees() {
        temp = start;
        int count = 0;
        do {
            count++;
            temp = temp.next;
        } while (temp != start);
        System.out.println("Number of employees: " + count);
    }

    public static void main(String[] args) {
        int choice;
        int employeeId;
        do {
            System.out.println("1. Add employee");
            System.out.println("2. Display employees in ascending order");
            System.out.println("3. Display employees in descending order");
            System.out.println("4. Search employee");
            System.out.println("5. Update employee");
            System.out.println("6. Count employees");
            System.out.println("7. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    addEmployee();
                    break;
                case 2:
                    displayAscending();
                    break;
                case 3:
                    displayDescending();
                    break;
                case 4:
                    System.out.print("Enter employee ID: ");
                    employeeId = scanner.nextInt();
                    searchEmployee(employeeId);
                    break;
                case 5:
                    System.out.print("Enter employee ID: ");
                    employeeId = scanner.nextInt();
                    updateEmployee(employeeId);
                    break;
                case 6:
                    countEmployees();
                    break;
                case 7:
                    System.exit(0);
                default:
                    System.out.println("Invalid choice.");
            }
        } while (true);
    }
}