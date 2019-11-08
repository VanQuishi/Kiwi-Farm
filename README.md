# Kiwi-Farm
University of Houston

Description
  You are a kiwi farmer that lives on your own kiwis. Kiwis
  are all that you eat. If you want to not die, you have to
  harvest and replant your kiwis.

Let’s say your kiwi farm is represented by a matrix:
4 6 8 9
0 0 1 0
7 7 5 6
2 1 7 7

Each number represents the
“ripeness” of a kiwi with 0 meaning
that it has just been planted and 6-8
meaning that it is at optimal ripeness.
If the ripeness exceeds 8, then the
fruit is considered rotten and inedible.
As each day passes, you will go through the following
procedure:

1. Check every row of your kiwi farm to see if the row can
be harvested. You can consider this by checking if at
least 50% of a row’s kiwis are at least ripe (at least 6).

2. If it is, the number of ripe and rotten kiwis will be
tallied and the entire row will be cleared and replanted
(an entire row of 0’s). Therefore the kiwis that aren’t fully
grown will be discarded. Although you are a wasteful
farmer, you probably don’t want your first homework to
be any harder.

3. At the end of the day any unharvested rows will age
by one day (incremented by 1). This means that the rows
the got cleared will stay as 0’s.
You will simulate your kiwi patch for seven days using
the provided procedure above. On the evening of the
seventh day, all rows will once again be checked for
harvest and tallied. Then present your yield. Your yield
(or output) will be the resulting matrix, then the total
number of harvested kiwis and rotten kiwis tallied
throughout the entire week.

Hints
- The kiwi matrix will always be a square and the size will
always be even (so calculating 50% will be easier)
- You are required to use pointers to solve the problem
