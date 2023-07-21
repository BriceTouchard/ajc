#! /bin/sh
#Écrire un programme qui prend en argument un entier qui correspond à une durée de temps en secondes
#Ce programme doit afficher le temps converti en une chaîne de caractères sous de forme “xx heures yy minutes zz secondes”
#En cas de valeur nulle ou unitaires pour les heures minutes et secondes, on ne mettra pas de s aux heures, minutes et secondes

# Jeu de données d'arguments
# 1h10min20sec = 3600+600+20 = 4220
# 2h00min00sec = 7200
# 2h43min56sec = 7200 + 2580 + 56 = 9836

# On teste si il y a un argument
[ ! $1 ] && ( echo "Message d'erreur : pas d'argument. (code 1)" ) && exit 1

h="heure"
m="minutes"
s="secondes"
heure=$(($1/3600))
minute=$(($1%3600/60))
seconde=$(($1%60))

[ $1 -ge 7200 ] && h=$h"s"
[ $minute -eq 0 ] && m="minute"
[ $seconde -eq 0 ] && s="seconde"

echo $heure $h $minute $m $seconde $s
