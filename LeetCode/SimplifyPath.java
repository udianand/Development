
/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

public class Solution {
    public String simplifyPath(String path) {
        StringBuilder sb = new StringBuilder("");
		String[] splitPath = path.split("/");

		Stack<String> stringStack = new Stack<String>();

		for (String s : splitPath) {
			if (s.equals("..")) {
				if (!stringStack.empty()) 
				        stringStack.pop();
			}

			else if (s.length() > 0 && !s.equals("."))
				stringStack.push(s);
		}

		for (String s : stringStack) {
			sb.append("/" + s);
		}

		String result = sb.toString();

		if (result.length() == 0)
			result = "/";

		return result;
        
    }
}
