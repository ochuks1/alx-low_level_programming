#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void display_elf_header(const char *file_name)
{
    int fd;
    Elf64_Ehdr elf_header;

    /* Open the ELF file */
    fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        dprintf(2, "Error: Cannot open file %s\n", file_name);
        exit(98);
    }

    /* Read the ELF header */
    if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header)) {
        dprintf(2, "Error: Cannot read ELF header from file %s\n", file_name);
        exit(98);
    }

    /*  Check for ELF magic */
    if (elf_header.e_ident[EI_MAG0] != ELFMAG0 || 
        elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
        elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
        elf_header.e_ident[EI_MAG3] != ELFMAG3) {
        dprintf(2, "Error: %s is not an ELF file\n", file_name);
        exit(98);
    }

    printf("Magic: %c%c%c%c%c%c%c%c%c%c\n",
           elf_header.e_ident[EI_MAG0],
           elf_header.e_ident[EI_MAG1],
           elf_header.e_ident[EI_MAG2],
           elf_header.e_ident[EI_MAG3],
           elf_header.e_ident[EI_MAG4],
           elf_header.e_ident[EI_MAG5],
           elf_header.e_ident[EI_MAG6],
           elf_header.e_ident[EI_MAG7],
           elf_header.e_ident[EI_MAG8],
           elf_header.e_ident[EI_MAG9]);

    printf("Class: %s\n", elf_header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
    printf("Data: %s\n", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("Version: %d (current)\n", elf_header.e_ident[EI_VERSION]);
    printf("OS/ABI: %s\n", elf_header.e_ident[EI_OSABI]);
    printf("ABI Version: %d\n", elf_header.e_ident[EI_ABIVERSION]);
    printf("Type: %d\n", elf_header.e_type);
    printf("Entry point address: 0x%lx\n", elf_header.e_entry);

    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        dprintf(2, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    display_elf_header(argv[1]);
    return 0;
}
