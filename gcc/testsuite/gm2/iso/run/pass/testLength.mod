(* Copyright (C) 2015 Free Software Foundation, Inc.  *)
(* This file is part of GNU Modula-2.

GNU Modula-2 is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GNU Modula-2 is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License along
with gm2; see the file COPYING.  If not, write to the Free Software
Foundation, 51 Franklin Street, Fifth Floor,
Boston, MA 02110-1301, USA.  *)

MODULE testLength ;   (*!m2iso*)

FROM NumberIO IMPORT WriteCard ;
FROM StrIO IMPORT WriteLn, WriteString ;
FROM M2RTS IMPORT Length ;

VAR
   s: ARRAY [0..50] OF CHAR ;
BEGIN
   s := "What?";

   WriteString("LENGTH(s) reports ") ;
   WriteCard(LENGTH(s), 4) ; WriteLn ;

   WriteString("Length(s) reports ") ;
   WriteCard(Length(s), 4) ; WriteLn ;
END testLength.
