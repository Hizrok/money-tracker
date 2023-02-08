# money-tracker

## documentation

### adding an item

```
add_item [type] [amount] ["name"]
```
- type can be income or expense
- amount is a float value
- name in entered in quotes ""
- category is "other" by default
- date is today as default (format: dd/mm/yyyy)
- generate random id

- posible errors:
	- invalid type
	- invalid amount
	- name not in quotes

### editing an item
```
edit_item [id] [field] ["value"]
```
- field can be type, amount, name, category or date

- posible errors:
	- id does not exist
	- invalid field
	- invalid field format

### removing an item
```
remove_item [id]
```

- posible errors:
	- id does not exist

## future versions
- category and date as optional parameters of add_item command
