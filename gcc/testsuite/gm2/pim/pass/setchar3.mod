(* Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc. *)
(* This file is part of GNU Modula-2.

GNU Modula-2 is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2, or (at your option) any later
version.

GNU Modula-2 is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License along
with gm2; see the file COPYING.  If not, write to the Free Software
Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA. *)

MODULE setchar3 ;

FROM SYSTEM IMPORT ADR ;

TYPE
   smallchar = SET OF ['A'..'Z'] ;

VAR
   s : smallchar ;
   ch: CHAR ;
   p : POINTER TO CARDINAL ;
BEGIN
   ch := 'z' ;
   s := smallchar{} ;
   s := smallchar{'A'} ;
   p := ADR(s) ;
   p^ := 1 ;
   p^ := 3 ;
   p^ := 7 ;
   p^ := 15 ;
   p^ := 31 ;
   p^ := 31
END setchar3.
