#pragma once
namespace homework5 {
void out (int *prt,int lengh_array);
int invert_binary (int *a);
int fill_binary (int *a, int marker, int step, int lengh_array);
void output_array (int lengh_array,int array []);
int initial_array (int *a,int lengh_array,int first_member, int increment);
int volume_array (int *);
int fun (int array [],int lengh_array,int marker);
void cond (int n,int lengh_array,int i0);

void rav (int, int lengh_array,int i0, int bufer, int prt);

void lev (int, int lengh_array,int i0,int j0, int bufer [], int *prt);
int cicle (int*,int );

template <typename... Types>
void invert(Types... ts);

}