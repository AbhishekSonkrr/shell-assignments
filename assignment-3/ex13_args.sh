# Exercise 13b: Write a shell script to find the scalar product of two vectors (By command line arguments).
n=$1; shift
if [ -z "$n" ] || [ $# -ne $((2*n)) ]; then echo "Usage: $0 <n> <v1...> <v2...>"; exit; fi
sum=0
for ((i=0;i<n;i++)); do
	v1=${@:$((i+1)):1}
	v2=${@:$((n+i+1)):1}
	sum=$((sum + v1 * v2))
done
echo "Scalar product: $sum"