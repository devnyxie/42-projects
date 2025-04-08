### ✅ **Done**
- Open input/output files
- Create a pipe
- Fork and execute cmd1 and cmd2
- Pass arguments to execve
- Basic error 
- Implement `PATH` resolution 🔍
- Add Makefile, compile libft and project correctly
- Norminette compliance
---

### 🛠️ **TODO List**

- **🧼 Free all heap allocations**  
    - Avoid memory leaks (especially split command arrays).

- **🚨 Better error messages**  
    - Use `perror()` smartly with file or cmd names.

- **🧪 Add input validation**  
    - Example: check if file1 exists before `open()`, command is valid, etc.

### Testing

```bash
./pipex input.txt "grep ignoreme" "wc -l" output.txt
```