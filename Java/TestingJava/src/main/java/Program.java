public class Program {
    public static void main(String[] args) {
        Person dave = new Person("Dave", 16);
        Person kyle = new Person("Kyle", 22);
        System.out.println("Dave is " + dave.age);
        System.out.println("Kyle is " + kyle.age);
        dave.getOlder();
        kyle.getOlder();
        System.out.println("Dave got older, dave is now " + dave.age);
        System.out.println("Kyle got older, dave is now " + kyle.age);
    }
}
