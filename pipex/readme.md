### ✅ **Current working features**
- Open input/output files
- Create a pipe
- Fork and execute cmd1 and cmd2
- Pass arguments to execve
- Basic error 
- Implement `PATH` resolution 🔍
- Add Makefile, compile libft and project correctly.
---

### 🛠️ **TODO List**

- **🧠 Use proper argument splitting**  
    - Replace dumb `strtok()` with your `ft_split()` (libft).

- **🧼 Free all heap allocations**  
    - Avoid memory leaks (especially split command arrays).

- **📁 Close all FDs** properly in parent and child  
    - Avoid leaking descriptors.

- **🚨 Better error messages**  
    - Use `perror()` smartly with file or cmd names.

- **🧪 Add input validation**  
    - Example: check if file1 exists before `open()`, command is valid, etc.

- **📋 Norminette compliance**  
    - Norme everything: `42` style.
