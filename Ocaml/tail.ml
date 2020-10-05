(* Author:      Simon Schoelkopf
 * Instructor:  William Killian
 * Date:        9/16/2020
 * Assignment:  Lab 2 - Tail Recursion
 * Description: This is a compilation of tail-recursive
 							  functions that do various things
 *)

(* 
	***** PROVIDE COMMENT BLOCKS AND IMPLEMENTATIONS FOR THE FOLLOWING FUNCTIONS ***** 
	***** INCLUDE TYPE SIGNATURES ***** 
*)

(*
	This function computes a square root of a float
	to a specified tolerence. 

	Type signature: float -> float -> float
*)
let rec sqrt tol x =
	let rec sqrtGuess tol x g=
		if  abs_float(g *. g -. x) <= tol then
			g
		else
			sqrtGuess (tol) (x) ((g +. x /. g) /. 2.0)

	in sqrtGuess (tol) (x)  (x/. 2.0)
;;
(* Your solution for sqrt2 should not need a lambda. Replace
	 everything to the right of the =. fun x -> failwith "to be written" *)
	 
(*
	This function calls a square root function
	to compute the given float to a tolerance of
	0.00001. 

	Type signature: float -> float
*)
let rec sqrt2 = 
	sqrt(0.00001)
;;

(*
	This is a non-tail recursive function that
	computes the factorial for a given int
	using if then else notation

	Type signature: int -> int
*)
let rec factorial1 x = 
	if x > 1 then
		factorial1(x - 1) * x
	else
		x
;;

(*
	This is a non-tail recursive function that
	computes the factorial for a given int
	using pattern matching

	Type signature: int -> int
*)
let rec factorial2 x = 
	match x - 1 with
		|0 -> x
		|_ -> factorial2(x - 1) * x

;;

(*
	This is a tail recursive function that
	computes the factorial for a given int
	using if then else notation

	Type signature: int -> int
*)
let rec factorial3 x = 
	let rec factorialHelper total x=
			if x = 1 then
				total
			else
				factorialHelper (total * x) (x - 1)
	in factorialHelper 1 x
;;


(*
	This is a tail recursive function that
	computes the xth fibbonacci number

	Type signature: int -> int
*)
let rec fibonacci x =
	let rec fibHelper current next x =
		match x with
			|0 -> current
			|1 -> next
			|_ -> fibHelper (next) (current + next) (x - 1)
	in fibHelper 0 1 x
;;

(*
	This is a tail-recursive list
	reverse function

	Type signature: 'a list -> 'a list
*)
let rec rev l =
	let rec revHelper l revl=
		match l with
		|[] -> revl
		|hd :: tl -> revHelper tl (hd :: revl)
	in revHelper l []
;;

(*
	This function takes in a list and 
	another function and then returns a list
	of the output from that function. 

	Type signature: ('a -> 'b) -> 'a list -> 'b list
*)
let rec map f l = 
	match l with
	| [] -> []
	| hd::_ -> f (List.hd l) :: map (f) (List.tl l)
;;

(*
	This tail-recursive function takes in a list and 
	another function and then returns a list
	of the output from that function. 

	Type signature: ('a -> 'b) -> 'a list -> 'b list
*)
let rec map2 f l =
	let rec mapHelper f l endList=
		match l with
		| [] -> rev(endList)
		| hd::_ -> mapHelper (f) (List.tl l) (f(List.hd l) :: endList)
	in mapHelper f l []
;;

(*
		This function prints a list
		of integers found between the 
		two integers it is given

	Type signature: int -> int -> int list
*)
let rec range a b = 
	if a > b then
		[]
	else
	a:: range(a + 1) (b)
;;

(*
	This function computes the square root
	of all the values in the range 1, 20 and 
	returns them in a list

	Type signature: float list
*)
let roots : float list =
	map (sqrt2) (List.map (fun ny -> float_of_int ny) (range(1) (20) ))

;;

let rec mystery1 (f:int->int) (s:int) (l:int list) =
  match l with
  | [] -> f s
  | h::t -> mystery1 f h t
	

	let poopy x =
		let y = 4 in
		let z = 2 in
		let x = y * y + z in
		y - z

		let f a b =
			if a > b then
				a
			else
				b
		;;
		
		let f10 = f 10
		;;