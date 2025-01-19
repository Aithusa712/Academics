public class Associate implements Customer {
	private String name;

	public Associate(String name) {
		this.name = name;
	}

	public void printName() {
		System.out.println(name);
	}

	public void printType() {
		System.out.println("Associate Type");
	}

}
