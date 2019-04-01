package ch1;

public class Main {

    public static void main(String[] args) {

        System.out.println("Beginning tests!");
        System.out.println("The first result should be false and the second should be true for boolean problems. Otherwise the output will be just the result.");
        System.out.println("<=============================================================>");
        System.out.println("<====Test Unique!====>");
        System.out.println(IsUnique.testUnique("test"));
        System.out.println(IsUnique.testUnique("cat"));
        System.out.println("<====Test Permutation====>");
        System.out.println(IsPermutation.testPermutation("test", "fail"));
        System.out.println(IsPermutation.testPermutation("test", "sett"));
        System.out.println("<====Test ch1.Urlify====>");
        System.out.println(Urlify.makeUrl("Hello World! This is a test!"));
    }
}
