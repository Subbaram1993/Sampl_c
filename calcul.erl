-module(calcul).
-export([calculator_input/2,
         calculator_menu/2,
         calculation/3]).
-author("subbaramaiah chevuru").

%Reading the inputs from the  User
calculator_input() ->
  Num1 = string:to_integer(io:fread("Choice : ", "~s")),
  Num1 = string:to_integer(io:fread("Choice : ", "~s"))
  calculator_menu(Num1, Num2).

%Reading input from user and perform calculation 
calculator_menu(Num1, Num2) ->
  io:format("~n1.Addition~n"),
  io:format("~n2.Subtraction~n"),
  io:format("~n3.Multiplication~n"),
  io:format("~n4.Division~n"),
  {ok,Term} = io:fread("Choice : ", "~s"),
  {Choice,_} = string:to_integer(Term),
  io:format("~nChoice is ~w~n",[Choice]),
  calculation(Choice,Num1,Num2).

%Performing calculation operations based on user selection 
calculation(Choice,Num1,Num2) ->
  if 
    Choice > 0 ->
      case Choice of 
        1 -> io:format("~n Addition is Selected ~n"),
          Result = Num1 + Num2,
          io:format("~n Result is :~p~n",[Result]);
        2 -> io:format("~n Subtraction is Selected ~n"),
          if 
           Num1 < Num2 -> 
             io:format("~n ~p is > ~p~n",[Num2, Num1]),
             Result = Num2 - Num1,
             io:format("~n Result is: ~p~n",[Result]);
           true ->
             Result = Num1 - Num2,
             io:format("~nResult is:~p~n",[Result])
         end;
        3 -> io:format("~n Multiplication is Selected ~n"),
          Result = Num1 * Num2,
          io:format("~n Result is ~p~n",[Result]);
        4 -> io:format("~n Division is Selected ~n"),
          if
            Num2 > 0 ->
              if
                Num1 > 0 ->
                  Result = Num1 / Num2,
                  io:format("~n Result is ~p~n",[Result]);
                true ->
                  Result = 0,
                  io:format("~n Result is ~p~n",[Result])
              end;
            true ->
              io:format("~nDivision cannot be performmed ~n")
          end
        end;
    true -> io:format("~n Wrong Selection ~n")
 end.
