package basics;

public class TestMemoryCell {

    public static void main(String[] args) {
        // MemoryCell m = new MemoryCell();
        // Integer p = Integer.valueOf(1304);
        // m.write(p);
        // System.out.println("Contents are: " + m.read());

        GenericMemoryCell<Integer> gm = new GenericMemoryCell<>();
        gm.write(Integer.valueOf(12));

    }
    
}
