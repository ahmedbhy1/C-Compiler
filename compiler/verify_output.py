import subprocess

# Expected output
expected_output = """\
    movl $5, %eax
    push %eax
    movl $3, %eax
    pop %ebx
    andl %ebx, %eax  # This is `a & b`

    push %eax
    movl $5, %eax
    push %eax
    movl $3, %eax
    pop %ebx
    orl %ebx, %eax  # This is `a | b`

    push %eax
    movl $5, %eax
    push %eax
    movl $3, %eax
    pop %ebx
    xorl %ebx, %eax  # This is `a ^ b`
"""

# Run the compiler and capture output
try:
    result = subprocess.run(["./ifcc", "test.c"], capture_output=True, text=True, check=True)
    generated_output = result.stdout.strip()

    # Save output to file
    with open("generated_output.s", "w") as f:
        f.write(generated_output)

    # Compare output
    if generated_output == expected_output.strip():
        print("Test Passed: Output matches expected assembly!")
    else:
        print("Test Failed: Output does not match expected assembly!")
        print("\nExpected Output:\n", expected_output)
        print("\nGenerated Output:\n", generated_output)

except subprocess.CalledProcessError as e:
    print(f"Error running compiler: {e}")

