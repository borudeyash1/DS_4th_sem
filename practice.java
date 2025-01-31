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
        System.out.println("department: " + department);
        System.out.println("designation: " + designation);
        System.out.println("Employee Id : " + employeeId);
        System.out.println("salary: " + salary);

    }
}

public class practice {
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
            newnode.next = temp;
            newnode.prev = start;
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
    public static void searchEmployee(int employee) {
        temp = start; 
        do {
            if(temp.employeeId == employee) {
              temp.display();
                return;
            }
            temp = temp.next;
        }while (temp  != start);
        System.out.println(x: "employee not found.");
    }
            
        
        public static void updateEmployee(int employee) {
            temp = start;
            do {
                if(temp.employeeId == employeeId) {
                    System.out.print(s: "Enter new name: ");
                    temp.name = scanner.next();
                    System.out.prit(s:"Enter new department: ");
                    temp.department =  scanner.next();
                    System.out.print(s: "Enter new designation: ");
                    temp.designation = scaner.next
                }
            }
        }
}

