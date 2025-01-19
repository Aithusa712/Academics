public class Paying implements Customer {

	private String name;

	public Paying(String name) {
		this.name = name;
	}

	public void printName() {
		System.out.println(name);
	}

	public void printType() {
		System.out.println("Paying");
	}

}
