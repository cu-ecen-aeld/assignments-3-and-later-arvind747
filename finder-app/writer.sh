if [ "$#" -ne 2 ]; then
   echo "incorrect arguments"
   exit 1
   fi

FILE="./$1"

mkdir -p "$(dirname "$FILE")" && touch "$FILE"
echo "$2" >"$FILE"
echo "" >>"$FILE"

