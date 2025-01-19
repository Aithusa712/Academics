public class App {
	public static void main(String[] args) {
		Customer p1 = new Paying("John");
		Customer a1 = new Associate("Andy");

		System.out.println("Interface");
		p1.printName();
		p1.printType();
		a1.printName();
		a1.printType();
	}
}
