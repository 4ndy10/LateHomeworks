int main() {
    const char mensaje[] = "Hola Mundo\n";

    // Llamada al sistema write
    __asm__ volatile (
        "mov $1, %%rax\n"         // Número de syscall: write
        "mov $1, %%rdi\n"         // Descriptor de archivo (stdout)
        "lea %0, %%rsi\n"         // Dirección del mensaje
        "mov $10, %%rdx\n"        // Longitud del mensaje
        "syscall\n"
        :
        : "m"(mensaje)            // Entrada: mensaje
        : "rax", "rdi", "rsi", "rdx"
    );

    // Llamada al sistema exit
    __asm__ volatile (
        "mov $60, %%rax\n"        // Número de syscall: exit
        "xor %%rdi, %%rdi\n"      // Código de salida 0
        "syscall\n"
        :
        :
        : "rax", "rdi"
    );
}
