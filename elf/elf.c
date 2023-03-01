#include <elf.h>
#include <stdio.h>

int main (int argc, char **argv) {

  int i;
  FILE *fp;
  Elf32_Ehdr elf_header;
  Elf32_Phdr prg_header;
  char code[0xc] = {
      0xB8,0x01,0x00,0x00,0x00,  //mov 0x1, eax ; exit
      0xBB,0x01,0x00,0x00,0x00,  //mov 0x1, ebx ; param
      0xCD,0x80                  //int 0x80     ; syscall
  };

  //elf header
  elf_header.e_ident[EI_MAG0] = ELFMAG0;
  elf_header.e_ident[EI_MAG1] = ELFMAG1;
  elf_header.e_ident[EI_MAG2] = ELFMAG2;
  elf_header.e_ident[EI_MAG3] = ELFMAG3;
  elf_header.e_ident[EI_CLASS] = ELFCLASS32;
  elf_header.e_ident[EI_DATA] = ELFDATA2LSB;
  elf_header.e_ident[EI_VERSION] = EV_CURRENT;
  elf_header.e_ident[EI_OSABI] = ELFOSABI_NONE;
  elf_header.e_ident[EI_ABIVERSION] = 0x00;
  elf_header.e_ident[EI_PAD] = 0x00;
  for(i = (EI_NIDENT - 1) ; i>EI_PAD ; i--){
    elf_header.e_ident[i] = 0x00;
  }
  elf_header.e_type = ET_EXEC; //executable
  elf_header.e_machine = EM_386; //386
  elf_header.e_version = EV_CURRENT; //version 0x1
  elf_header.e_entry = 0x08048000 + 0x34 + 0x20; //52 + 32 = 84 (0x54) + 0x08048000
  elf_header.e_phoff = 0x34; // 52 = (0x34)
  elf_header.e_shoff = 0x00000000; //no section
  elf_header.e_flags = 0x00000000; // x86
  elf_header.e_ehsize = 0x34; // 32 bitis -> 52 = (0x34)
  elf_header.e_phentsize = 0x20; //32 bits -> 32 = (0x20)
  elf_header.e_phnum = 0x01; //1 program header
  elf_header.e_shentsize = 0x28; //32 bits
  elf_header.e_shnum = 0x0000; //no section
  elf_header.e_shstrndx = 0x0000; //no section

  //prg_header
  prg_header.p_type = PT_LOAD;
  prg_header.p_offset = 0x54;
  prg_header.p_vaddr = 0x08048000 + 0x34 + 0x20; //52 + 32 = 84 (0x54) + 0x08048000
  prg_header.p_paddr = 0x00000000;
  prg_header.p_filesz = 0xc; //12 bytes
  prg_header.p_memsz = 0xc;
  prg_header.p_flags = PF_R | PF_X;
  prg_header.p_align = 0x1000; //x86

  //save
  fp = fopen("mini","w");
  fwrite(&elf_header,1,sizeof(Elf32_Ehdr),fp);
  fwrite(&prg_header,1,sizeof(Elf32_Phdr),fp);
  fwrite(&code,1,0xc,fp);
  fclose(fp);

  return 0;

}
