<h2><a href="https://leetcode.com/problems/recyclable-and-low-fat-products">SQL 1: Recyclable and Low Fat Products</a></h2> <img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' /><hr><p>Table: <code>Products</code></p>

## Problem explained (in detail)

You have a table `Products` with three columns:

* `product_id` (int) — unique id for each product (primary key).
* `low_fats` (ENUM('Y','N')) — `'Y'` means the product is low fat, `'N'` means it is not.
* `recyclable` (ENUM('Y','N')) — `'Y'` means the product is recyclable, `'N'` means it is not.

Goal: return the `product_id` values of products that satisfy both conditions: `low_fats = 'Y'` and `recyclable = 'Y'`. Order of rows does not matter.

This is a simple filter / selection problem: pick rows where both boolean-like columns are `'Y'`.

---

# Schema (SQL) — provided and reproducible

```sql
-- create table (if not exists)
CREATE TABLE IF NOT EXISTS Products (
    product_id INT,
    low_fats ENUM('Y', 'N'),
    recyclable ENUM('Y', 'N')
);

-- empty the table for a fresh example
TRUNCATE TABLE Products;

-- insert sample rows
INSERT INTO Products (product_id, low_fats, recyclable) VALUES (0, 'Y', 'N');
INSERT INTO Products (product_id, low_fats, recyclable) VALUES (1, 'Y', 'Y');
INSERT INTO Products (product_id, low_fats, recyclable) VALUES (2, 'N', 'Y');
INSERT INTO Products (product_id, low_fats, recyclable) VALUES (3, 'Y', 'Y');
INSERT INTO Products (product_id, low_fats, recyclable) VALUES (4, 'N', 'N');
```

# Pandas Schema
```
data = [['0', 'Y', 'N'], ['1', 'Y', 'Y'], ['2', 'N', 'Y'], ['3', 'Y', 'Y'], ['4', 'N', 'N']]
products = pd.DataFrame(data, columns=['product_id', 'low_fats', 'recyclable']).astype({'product_id':'int64', 'low_fats':'category', 'recyclable':'category'})
```
---

# Intuition

Check each product — if it is low fat (`low_fats = 'Y'`) **and** recyclable (`recyclable = 'Y'`), include its `product_id` in the output. It's a straightforward row filter.

---

# Approach

Use a single `SELECT` with a `WHERE` clause combining both conditions with `AND`. In Pandas, apply a boolean mask using `&`. Complexity is linear in number of rows since you check each row once.

---

# Complexity

* **Time complexity:** O(n) — one pass over the `Products` table / DataFrame with `n` rows.  
* **Space complexity:** O(1) additional space (ignoring output), only a couple of temporary variables/filters.

---

---

# Example (Input → Output)

**Input `Products` table:**

| product_id | low_fats | recyclable |
| ---------- | -------- | ---------- |
| 0          | Y        | N          |
| 1          | Y        | Y          |
| 2          | N        | Y          |
| 3          | Y        | Y          |
| 4          | N        | N          |

**Expected output (any order):**

| product_id |
| ---------- |
| 1          |
| 3          |

**Explanation:** Only product `1` and product `3` have both `low_fats = 'Y'` and `recyclable = 'Y'`.

---
---

# Code
---
### MySQL

```mysql
# Approach 1 Simple
-- Simple, readable query: filter on both columns being 'Y'
SELECT product_id
FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y';


# Approach 2 Dynamic
select product_id from Products where Products.recyclable ='Y' and Products.low_fats = 'Y' 
```
---
---
---
### Equalent Python code

```python
import pandas as pd

# sample data (matches schema and example)
data = [
        [0, 'Y', 'N'],
        [1, 'Y', 'Y'],
        [2, 'N', 'Y'],
        [3, 'Y', 'Y'],
        [4, 'N', 'N']
]
products = pd.DataFrame(data, columns=['product_id', 'low_fats', 'recyclable']) \
                         .astype({'product_id':'int64', 'low_fats':'category', 'recyclable':'category'})

# filter where both columns are 'Y'
result = products[(products['low_fats'] == 'Y') & (products['recyclable'] == 'Y')][['product_id']]

print(result)
# Expected printed output (order may vary):
#    product_id
# 1           1
# 3           3
```

---

# Notes / Variations

* The `ENUM` columns behave like categorical strings — comparing to `'Y'` is correct.
* Some SQL platforms allow `TRUE/FALSE` booleans — here the question uses `'Y'/'N'`.
* If you had to return rows in a specific order, add `ORDER BY product_id` (not required here).

---
