/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package first.program;

/**
 *
 * @author Ben
 */
public class FirstProgram {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Person dave = new Person("Dave");
        System.out.println(dave.Name);
    }
}

class Person {
    public String Name;
    public Person(String name) {
        Name = name;
    }
}
