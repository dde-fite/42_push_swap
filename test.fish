#!/usr/bin/fish
echo "============= PUSH_SWAP_TESTER =============";
echo "                  dde-fite                  ";
echo "";

echo "Testing 100 Numbers";
echo " - Test 1:";
set args (seq -214747 214747 | sort -R | head -n 100); ./push_swap $args | wc -l;
./push_swap $args | ./checker $args;
echo ""
echo " - Test 2:";
set args (seq -214747 214747 | sort -R | head -n 100); ./push_swap $args | wc -l;
./push_swap $args | ./checker $args;
echo ""
echo " - Test 3:";
set args (seq -214747 214747 | sort -R | head -n 100); ./push_swap $args | wc -l;
./push_swap $args | ./checker $args;
echo ""
echo " - Test 4:";
set args (seq -214747 214747 | sort -R | head -n 100); ./push_swap $args | wc -l;
./push_swap $args | ./checker $args;
echo ""
echo " - Test 5:";
set args (seq -214747 214747 | sort -R | head -n 100); ./push_swap $args | wc -l;
./push_swap $args | ./checker $args;
echo "";
echo "Testing 500 Numbers";
echo " - Test 1:";
set args (seq -214747 214747 | sort -R | head -n 500); ./push_swap $args | wc -l;
./push_swap $args | ./checker $args;
echo ""
echo " - Test 2:";
set args (seq -214747 214747 | sort -R | head -n 500); ./push_swap $args | wc -l;
./push_swap $args | ./checker $args;
echo ""
echo " - Test 3:";
set args (seq -214747 214747 | sort -R | head -n 500); ./push_swap $args | wc -l;
./push_swap $args | ./checker $args;
echo ""
echo " - Test 4:";
set args (seq -214747 214747 | sort -R | head -n 500); ./push_swap $args | wc -l;
./push_swap $args | ./checker $args;
echo ""
echo " - Test 5:";
set args (seq -214747 214747 | sort -R | head -n 500); ./push_swap $args | wc -l;
./push_swap $args | ./checker $args;3