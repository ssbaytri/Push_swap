<div align="center">

# 🔄 Push_swap

<img src="https://drive.google.com/uc?id=1-WuFTHm-YSncU0uGDddOyLOb_1-IDHZT" alt="Push_swap Header" width="100%">

### 42 School Project: A Journey in Stack Sorting 🎯
*Transforming chaos into order, one stack at a time* 

</div>

## 📚 Project Overview

Push_swap is a challenging algorithmic project from the 42 School curriculum that tests students' ability to implement efficient sorting algorithms. The task involves sorting a stack of integers using two stacks (A and B) with a limited set of operations, while minimizing the number of moves.

## 🧮 Algorithm Implementation

Our sorting strategy combines elegant solutions for small datasets with a powerful chunk-based approach for larger sets. Here's how it works:

### 🎯 Small Stack Handling (2-5 elements)
- **2 elements**: `sa` when needed
- **3 elements**: Optimized three-number sorting patterns
- **4 elements**: Strategic pushing and rotation sequence
- **5 elements**: Specialized five-number sorting algorithm

### 🚀 Large Stack Algorithm (>5 elements)
The algorithm operates in two main phases:

#### Phase 1: 📤 Pushing Elements to Stack B
The algorithm implements a dynamic chunking strategy:

1. **Window Calculation** 📏
   - Dynamic window size: `max = 0.05 * stack_size + 10`
   - Window continuously slides up as elements are pushed
   - Minimum threshold tracks the lower bound of current chunk

2. **Element Distribution** ⚡
   ```c
   // For each element in stack A:
   if (element_index >= min && element_index <= max)
       push to B                    // pb
   else if (element_index < min)
       push to B and rotate B       // pb, rb
   else
       rotate A                     // ra
   ```

3. **Optimization Features** ⚙️
   - Elements below minimum are pushed and rotated for better positioning
   - Window size adapts to total stack size for optimal performance
   - Smart rotation direction selection

#### Phase 2: 📥 Reconstructing Stack A
The algorithm rebuilds the sorted stack through:

1. **Maximum Element Location** 🎯
   - Efficiently finds the position of the maximum index in Stack B
   - Calculates optimal rotation direction

2. **Efficient Movement** ⚡
   ```c
   while (elements in stack B)
       if (top_element is current_max)
           push to A                // pa
       else if (max_position < size/2)
           rotate B up              // rb
       else
           rotate B down            // rrb
   ```

3. **Position Optimization** 🔄
   - Chooses rotation direction based on element position
   - Minimizes operations through path optimization

### ⚡ Performance Characteristics

- **Time Complexity**: O(n log n) average case
- **Space Complexity**: O(n) using two stacks
- **Operation Counts** 📊:
  - 100 numbers: < 700 operations
  - 500 numbers: < 5500 operations

## 🛠️ Available Operations

- `sa`: Swap first two elements of stack A
- `sb`: Swap first two elements of stack B
- `ss`: sa and sb simultaneously
- `pa`: Push top element from stack B to stack A
- `pb`: Push top element from stack A to stack B
- `ra`: Rotate stack A up
- `rb`: Rotate stack B up
- `rr`: ra and rb simultaneously
- `rra`: Rotate stack A down
- `rrb`: Rotate stack B down
- `rrr`: rra and rrb simultaneously

## 🎮 Usage

```bash
# Compilation
make

# Basic usage
./push_swap 4 67 3 87 23

# With checker (bonus)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## ✨ Bonus Part: Checker Program

The checker program is a crucial tool for validating the sorting operations of push_swap. Here's how it works:

### 🔍 Functionality
1. **Input Processing**
   - Reads the initial stack configuration
   - Accepts push_swap operations via standard input
   - Validates operation format and sequence

2. **Operation Execution**
   - Performs each operation on its own copy of the stacks
   - Maintains operation integrity and stack consistency
   - Tracks stack state after each operation

3. **Result Validation** ✅
   - Verifies final stack order
   - Checks if Stack B is empty
   - Returns appropriate status:
     - `OK`: Stack is perfectly sorted
     - `KO`: Stack is not sorted or Stack B not empty
     - `Error`: Invalid operations detected

### 🚀 Usage Examples
```bash
# Basic checker usage
./checker 3 2 1
sa
rra
pb
pa
OK

# Pipe with push_swap
./push_swap 3 2 1 | ./checker 3 2 1

# Multiple number testing
ARG=$(shuf -i 1-100 -n 50 | tr "\n" " "); ./push_swap $ARG | ./checker $ARG
```

## ⚠️ Error Handling

Robust error checking for:
- Non-integer inputs ❌
- Duplicate numbers 🔄
- Integer overflow/underflow 📊
- Empty input 💨
- Invalid argument formats 🚫

## 🧪 Testing and Validation

- Comprehensive test suite included
- Edge case handling
- Performance benchmarking tools
- Memory leak checking

## 📦 Dependencies

- C compiler (gcc/clang)
- Make
- Standard C library

## 📄 License

This project is distributed under the MIT license. See `LICENSE` file for more information.

---

<div align="center">

📚 **Part of the 42 School Curriculum**

*Made with ❤️ and lots of ☕*

</div>
