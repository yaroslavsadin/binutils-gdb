/* Replace functions for the ARC relocs.
   Copyright (C) 2015-2022 Free Software Foundation, Inc.

   This file is part of GAS, the GNU Assembler, GDB, the GNU debugger, and
   the GNU Binutils.

   GAS/GDB is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GAS/GDB is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GAS or GDB; see the file COPYING3.  If not, write to
   the Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

/* mask  = 00000000000000000000000000000000.  */
#ifndef REPLACE_none
#define REPLACE_none
ATTRIBUTE_UNUSED static bfd_vma
replace_none (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0x00;

  return insn;
}

#endif /* REPLACE_none */

/* mask  = 11111111.  */
#ifndef REPLACE_bits8
#define REPLACE_bits8
ATTRIBUTE_UNUSED static bfd_vma
replace_bits8 (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0xff;
  insn |= ((value >> 0) & 0x00ff) << 0;

  return insn;
}

#endif /* REPLACE_bits8 */

/* mask  = 1111111111111111.  */
#ifndef REPLACE_bits16
#define REPLACE_bits16
ATTRIBUTE_UNUSED static bfd_vma
replace_bits16 (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0xffff;
  insn |= ((value >> 0) & 0xffff) << 0;

  return insn;
}

#endif /* REPLACE_bits16 */

/* mask  = 111111111111111111111111.  */
#ifndef REPLACE_bits24
#define REPLACE_bits24
ATTRIBUTE_UNUSED static bfd_vma
replace_bits24 (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0xffffff;
  insn |= ((value >> 0) & 0xffffff) << 0;

  return insn;
}

#endif /* REPLACE_bits24 */

/* Special 24 bit replace for big endian.  */
/* mask  = 111111111111111111111111.  */
#ifndef REPLACE_bits24_be
#define REPLACE_bits24_be
ATTRIBUTE_UNUSED static bfd_vma
replace_bits24_be (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0xffffff00;
  insn |= ((value >> 0) & 0xffffff) << 8;

  return insn;
}

#endif /* REPLACE_bits24_be */

/* mask  = 11111111111111111111111111111111.  */
#ifndef REPLACE_word32
#define REPLACE_word32
ATTRIBUTE_UNUSED static bfd_vma
replace_word32 (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0xffffffff;
  insn |= ((value >> 0) & 0xffffffff) << 0;

  return insn;
}
#endif /* REPLACE_word32 */

/* mask  = 1111111111111111111111111111111111111111111111111111111111111111.  */
#ifndef REPLACE_word64
#define REPLACE_word64
ATTRIBUTE_UNUSED static bfd_vma
replace_word64 (bfd_vma insn, bfd_vma value)
{
  insn |= value;

  return insn;
}
#endif /* REPLACE_word64 */


/* mask  = 0000000000000000000000000000000011111111111111111111111111111111.  */
#ifndef REPLACE_limm
#define REPLACE_limm
ATTRIBUTE_UNUSED static bfd_vma
replace_limm (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0xffffffff;
  insn |= ((value >> 0) & 0xffffffff) << 0;

  return insn;
}

#endif /* REPLACE_limm */

/* mask  = 000000000000000011111111111111111111111111111111.  */
#ifndef REPLACE_limms
#define REPLACE_limms
ATTRIBUTE_UNUSED static bfd_vma
replace_limms (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0xffffffff;
  insn |= ((value >> 0) & 0xffffffff) << 0;

  return insn;
}

#endif /* REPLACE_limms */

/* mask  = 00000111111111102222222222000000.  */
#ifndef REPLACE_disp21h
#define REPLACE_disp21h
ATTRIBUTE_UNUSED static bfd_vma
replace_disp21h (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0x7feffc0;
  insn |= ((value >> 0) & 0x03ff) << 17;
  insn |= ((value >> 10) & 0x03ff) << 6;

  return insn;
}

#endif /* REPLACE_disp21h */

/* mask  = 00000111111111002222222222000000.  */
#ifndef REPLACE_disp21w
#define REPLACE_disp21w
ATTRIBUTE_UNUSED static bfd_vma
replace_disp21w (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0x7fcffc0;
  insn |= ((value >> 0) & 0x01ff) << 18;
  insn |= ((value >> 9) & 0x03ff) << 6;

  return insn;
}

#endif /* REPLACE_disp21w */

/* mask  = 00000111111111102222222222003333.  */
#ifndef REPLACE_disp25h
#define REPLACE_disp25h
ATTRIBUTE_UNUSED static bfd_vma
replace_disp25h (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0x7feffcf;
  insn |= ((value >> 0) & 0x03ff) << 17;
  insn |= ((value >> 10) & 0x03ff) << 6;
  insn |= ((value >> 20) & 0x000f) << 0;

  return insn;
}

#endif /* REPLACE_disp25h */

/* mask  = 00000111111111002222222222003333.  */
#ifndef REPLACE_disp25w
#define REPLACE_disp25w
ATTRIBUTE_UNUSED static bfd_vma
replace_disp25w (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0x7fcffcf;
  insn |= ((value >> 0) & 0x01ff) << 18;
  insn |= ((value >> 9) & 0x03ff) << 6;
  insn |= ((value >> 19) & 0x000f) << 0;

  return insn;
}

#endif /* REPLACE_disp25w */

/* mask  = 00000000000000000000000111111111.  */
#ifndef REPLACE_disp9
#define REPLACE_disp9
ATTRIBUTE_UNUSED static bfd_vma
replace_disp9 (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0x1ff;
  insn |= ((value >> 0) & 0x01ff) << 0;

  return insn;
}

#endif /* REPLACE_disp9 */

/* mask  = 00000000111111112000000000000000.  */
#ifndef REPLACE_disp9ls
#define REPLACE_disp9ls
ATTRIBUTE_UNUSED static bfd_vma
replace_disp9ls (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0xff8000;
  insn |= ((value >> 0) & 0x00ff) << 16;
  insn |= ((value >> 8) & 0x0001) << 15;

  return insn;
}

#endif /* REPLACE_disp9ls */

/* mask  = 0000000111111111.  */
#ifndef REPLACE_disp9s
#define REPLACE_disp9s
ATTRIBUTE_UNUSED static bfd_vma
replace_disp9s (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0x1ff;
  insn |= ((value >> 0) & 0x01ff) << 0;

  return insn;
}

#endif /* REPLACE_disp9s */

/* mask  = 0000011111111111.  */
#ifndef REPLACE_disp13s
#define REPLACE_disp13s
ATTRIBUTE_UNUSED static bfd_vma
replace_disp13s (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0x7ff;
  insn |= ((value >> 0) & 0x07ff) << 0;

  return insn;
}

#endif /* REPLACE_disp13s */

/* mask  = 0000022222200111.  */
#ifndef REPLACE_disp9s1
#define REPLACE_disp9s1
ATTRIBUTE_UNUSED static bfd_vma
replace_disp9s1 (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0x7e7;
  insn |= ((value >> 0) & 0x0007) << 0;
  insn |= ((value >> 3) & 0x003f) << 5;

  return insn;
}

#endif /* REPLACE_disp9s1 */

/* mask  = 00000000000000000000111111222222.  */
#ifndef REPLACE_disp12s
#define REPLACE_disp12s
ATTRIBUTE_UNUSED static bfd_vma
replace_disp12s (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0xfff;
  insn |= ((value >> 0) & 0x003f) << 6;
  insn |= ((value >> 6) & 0x003f) << 0;
  return insn;
}

#endif /* REPLACE_disp12s */

/* mask  = 0000001111111111.  */
#ifndef REPLACE_jli
#define REPLACE_jli
ATTRIBUTE_UNUSED static bfd_vma
replace_jli (bfd_vma insn, bfd_vma value)
{
  insn = insn & ~0x3ff;
  insn |= ((value >> 0) & 0x03ff) << 0;

  return insn;
}

#endif /* REPLACE_jli */

#ifndef REPLACE_disp8ls
#define REPLACE_disp8ls
/* mask = 0000 0000 1111 1110 2000 0000 0000 0000.  */
ATTRIBUTE_UNUSED static bfd_vma
replace_disp8ls (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0xfe8000;
  insn |= ((value >> 0) & 0x007f) << 17;
  insn |= ((value >> 7) & 0x0001) << 15;

  return insn;
}
#endif /* REPLACE_disp8ls */

#ifndef REPLACE_disp9s
#define REPLACE_disp9s
/* mask = 0000000111111111
   insn = 1111001sssssssss.  */
static bfd_vma
replace_disp9s (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0x1ff;
  insn |= ((value >> 0) & 0x01ff) << 0;

  return insn;
}
#endif /* REPLACE_disp9s */

#ifndef REPLACE_disp6s
#define REPLACE_disp6s
/* mask = 0000000000111111
   insn = 1111011000ssssss.  */
ATTRIBUTE_UNUSED static bfd_vma
replace_disp6s (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0x3f;
  insn |= ((value >> 0) & 0x003f) << 0;

  return insn;
}

#endif /* REPLACE_disp6s */

#ifndef REPLACE_disp7s
#define REPLACE_disp7s
/* mask = 0000000001111111
   insn = 11101bbb1sssssss.  */
ATTRIBUTE_UNUSED static bfd_vma
replace_disp7s (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0x7f;
  insn |= ((value >> 0) & 0x007f) << 0;

  return insn;
}
#endif /* REPLACE_disp7s */

#ifndef REPLACE_disp12s
#define REPLACE_disp12s
/* mask = 00000000000000000000111111222222
   insn = 00100RRR101010000RRRssssssSSSSSS.  */
ATTRIBUTE_UNUSED static bfd_vma
replace_disp12s (bfd_vma insn, bfd_vma value ATTRIBUTE_UNUSED)
{
  insn = insn & ~0xfff;
  insn |= ((value >> 0) & 0x003f) << 6;
  insn |= ((value >> 6) & 0x003f) << 0;

  return insn;
}
#endif /* REPLACE_disp12s */
