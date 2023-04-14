#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void check_elf(const unsigned char *e_ident);
void print_magic(const unsigned char *e_ident);
void print_class(const unsigned char *e_ident);
void print_data(const unsigned char *e_ident);
void print_version(const unsigned char *e_ident);
void print_osabi(const unsigned char *e_ident);
void print_type(unsigned int e_type, const unsigned char *e_ident);
void print_entry(unsigned long int e_entry, const unsigned char *e_ident);
void close_elf(int fd);

int main(int argc, char *argv[]) {
    int fd, ret;
    unsigned char e_ident[EI_NIDENT];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ELF-file>\n", argv[0]);
        return (EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error");
        return (EXIT_FAILURE);
    }

    ret = read(fd, e_ident, EI_NIDENT);
    if (ret == -1) {
        perror("Error");
        close_elf(fd);
        return (EXIT_FAILURE);
    }
    if (ret != EI_NIDENT) {
        fprintf(stderr, "Error: Failed to read ELF header\n");
        close_elf(fd);
        return (EXIT_FAILURE);
    }

    check_elf(e_ident);
    print_magic(e_ident);
    print_class(e_ident);
    print_data(e_ident);
    print_version(e_ident);
    print_abi(e_ident);
    print_osabi(e_ident);

    close_elf(fd);
    return (EXIT_SUCCESS);
}

void check_elf(const unsigned char *e_ident) {
    if (!(e_ident[0] == ELFMAG0 && e_ident[1] == ELFMAG1
        && e_ident[2] == ELFMAG2 && e_ident[3] == ELFMAG3)) {
        fprintf(stderr, "Error: Not an ELF file\n");
        exit(EXIT_FAILURE);
    }
}

void print_magic(const unsigned char *e_ident) {
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; ++i) {
        printf("%02x", e_ident[i]);
        if (i == EI_NIDENT - 1) printf("\n");
        else printf(" ");
    }
}

void print_class(const unsigned char *e_ident) {
    printf("  Class:                             ");
    switch (e_ident[EI_CLASS]) {
        case ELFCLASSNONE: printf("none\n"); break;
        case ELFCLASS32:   printf("ELF32\n"); break;
        case ELFCLASS64:   printf("ELF64\n"); break;
        default:           printf("<unknown: %x>\n", e_ident[EI_CLASS]); break;
    }
}

void print_data(const unsigned char *e_ident) {
    printf("  Data:                              ");
    switch (e_ident[EI_DATA]) {
        case ELFDATANONE:  printf("none\n"); break;
        case ELFDATA2LSB:  printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB:  printf("2's complement, big endian\n"); break;
        default:           printf("<unknown: %x>\n", e_ident[EI_DATA]); break;
    }
}

void print_version(const unsigned char *e

