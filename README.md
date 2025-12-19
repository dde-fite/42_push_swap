# 42_push_swap

# Testing

```fish
set args (seq -214748 214748 | sort -R | head -n 100); ./push_swap $args | wc -l
```

```fish
set args (seq -214748 214748 | sort -R | head -n 100); ./push_swap $args | ./checker $args
```
