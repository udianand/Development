
/*
 * WAP to compute all permutation of a given string.
 * */

import java.util.HashSet;
import java.util.Set;

public class StringPermutations {

	public static Set<String> Permute(String str)
	{
		Set <String> permSet = new HashSet <String>();
		
		if (str.length() <= 1)
		{
			permSet.add(str);
			return permSet;
		}
		
		char initial = str.charAt(0); // Remove the first character.
		String remaining = str.substring(1); // Complete string except the first character.
		Set <String> permRem = new HashSet<String>();
		permRem = Permute(remaining);
		
		for (String remStr: permRem)
		{
			for (int i = 0; i <= remStr.length(); i++)
			{
				String begin = remStr.substring(0,i);
				String end = remStr.substring(i); 
				String combineStr = begin + initial + end;
				permSet.add(combineStr);
			}
		}
		return permSet;
	}
	
	public static void main (String args[])
	{
		String s = "ABC";
		
		System.out.println("Permutations for string " + s + " are: " + Permute(s) );
	}
}
