
/** New_IO.java 
  Uses the Scanner class of Java API to read input
 Also, uses the printf method for formatted output
*/
import java.util.Scanner;
// Scanner class must be imported

public class NEW_IO {
	public static void main(String[] args) {

		Scanner keyboard = new Scanner(System.in);
		int temp1, temp2;

		System.out.printf("%n%s%n%s%n", "Welcome to ICT373!", "The Unit Coordinator is Ferdous Sohel.");
		System.out.printf("\nEnter 2 integers:");

		temp1 = keyboard.nextInt();
		temp2 = keyboard.nextInt();

		keyboard.nextLine(); // To skip past the end of line marker

		System.out.printf("%s%d%s%d\n\n",
				"The numbers are:", temp1, " and ", temp2);

		if (temp1 >= temp2)
			System.out.printf("Today's maximum forecast temperature is %d%n%n", temp1);
		else
			System.out.printf("Today's maximum forecast temperature is %d\n\n", temp2);

		System.out.println("Enter your name:");

		String name = keyboard.nextLine(); // read a string

		System.out.println("You entered:");
		System.out.printf("%s%n", name);
		System.out.println();

		keyboard.close();

	}// end of main
}// end of class
