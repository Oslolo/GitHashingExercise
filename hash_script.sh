
# Check if an argument was provided
if [ $# -eq 0 ]; then
  echo "Usage: $0 <4-digit number>"
  exit 1
fi

# Get the 4-digit number from the argument
input=$1

# Generate the hash using SHA-256
hash=$(echo -n "$input" | sha256sum | awk '{ print $1 }')

# Save the result to hash_output.txt
echo "Input: $input" > hash_output.txt
echo "Hash: $hash" >> hash_output.txt

# Print the hash to the terminal
echo "Hash for input $input: $hash"
