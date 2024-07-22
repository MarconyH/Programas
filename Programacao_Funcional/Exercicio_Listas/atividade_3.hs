import Data.Char (ord)

bin_hex_map :: String -> Char
bin_hex_map "0000" = '0'
bin_hex_map "0001" = '1'
bin_hex_map "0010" = '2'
bin_hex_map "0011" = '3'
bin_hex_map "0100" = '4'
bin_hex_map "0101" = '5'
bin_hex_map "0110" = '6'
bin_hex_map "0111" = '7'
bin_hex_map "1000" = '8'
bin_hex_map "1001" = '9'
bin_hex_map "1010" = 'A'
bin_hex_map "1011" = 'B'
bin_hex_map "1100" = 'C'
bin_hex_map "1101" = 'D'
bin_hex_map "1110" = 'E'
bin_hex_map "1111" = 'F'
bin_hex_map _      = error "Invalid input"

bin_hex :: String -> String
bin_hex [] = []
bin_hex binStr =
    let paddedBinStr = if length binStr `mod` 4 /= 0
                       then replicate (4 - (length binStr `mod` 4)) '0' ++ binStr
                       else binStr
        groupsOf4 = groupBy 4 paddedBinStr
    in map bin_hex_map groupsOf4

groupBy :: Int -> String -> [String]
groupBy _ [] = []
groupBy n xs = take n xs : groupBy n (drop n xs)