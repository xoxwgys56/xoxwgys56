# Get variable name string

source: [convert-variable-name-to-string](https://stackoverflow.com/questions/1534504/convert-variable-name-to-string)

## TL;DR

Not possible. See [conclusion](#conclusion) at the end.

---

There is an usage scenario where you might need this. I'm not implying there are not better ways or achieving the same functionality.

This would be useful in order to 'dump' an arbitrary list of dictionaries in case of error, in debug modes and other similar situations.

What would be needed, is the reverse of the `eval()` function:

```python
get_indentifier_name_missing_function()
```

which would take an identifier name ('variable','dictionary',etc) as an argument, and return a string containing the identifier’s name.

---

Consider the following current state of affairs:

```python
random_function(argument_data)
```

If one is passing an identifier name ('function','variable','dictionary',etc) `argument_data` to a `random_function()` (another identifier name), one actually passes an identifier (e.g.: `<argument_data object at 0xb1ce10>`) to another identifier (e.g.: `<function random_function at 0xafff78>`):

```python
<function random_function at 0xafff78>(<argument_data object at 0xb1ce10>)
```

From my understanding, only the memory address is passed to the function:

```python
<function at 0xafff78>(<object at 0xb1ce10>)
```

Therefore, one would need to pass a string as an argument to `random_function()` in order for that function to have the argument's identifier name:

```python
random_function('argument_data')
```

Inside the random_function()

```python
def random_function(first_argument):
```

, one would use the already supplied string `'argument_data'` to:

1. serve as an 'identifier name' (to display, log, string split/concat, whatever)
2. feed the `eval()` function in order to get a reference to the actual identifier, and therefore, a reference to the real data:

```python
print("Currently working on", first_argument)
some_internal_var = eval(first_argument)
print("here comes the data: " + str(some_internal_var))
```

Unfortunately, this doesn't work in all cases. It only works if the `random_function()` can resolve the `'argument_data'` string to an actual identifier. I.e. If `argument_data` identifier name is available in the `random_function()`'s namespace.

This isn't always the case:

```python
# main1.py
import some_module1

argument_data = 'my data'

some_module1.random_function('argument_data')

# some_module1.py
def random_function(first_argument):
    print("Currently working on", first_argument)
    some_internal_var = eval(first_argument)
    print("here comes the data: " + str(some_internal_var))
######
```

Expected results would be:

```plain
Currently working on: argument_data
here comes the data: my data
```

Because `argument_data` identifier name is not available in the `random_function()`'s namespace, this would yield instead:

```python
# Currently working on argument_data

Traceback (most recent call last):
  File "~/main1.py", line 6, in <module>
    some_module1.random_function('argument_data')
  File "~/some_module1.py", line 4, in random_function
    some_internal_var = eval(first_argument)
  File "<string>", line 1, in <module>
NameError: name 'argument_data' is not defined
```

---

Now, consider the hypotetical usage of a `get_indentifier_name_missing_function()` which would behave as described above.

Here's a dummy Python 3.0 code: .

```python
# main2.py
import some_module2
some_dictionary_1       = { 'definition_1':'text_1',
                            'definition_2':'text_2',
                            'etc':'etc.' }
some_other_dictionary_2 = { 'key_3':'value_3',
                            'key_4':'value_4',
                            'etc':'etc.' }
#
# more such stuff
#
some_other_dictionary_n = { 'random_n':'random_n',
                            'etc':'etc.' }

for each_one_of_my_dictionaries in ( some_dictionary_1,
                                     some_other_dictionary_2,
                                     ...,
                                     some_other_dictionary_n ):
    some_module2.some_function(each_one_of_my_dictionaries)

# some_module2.py
def some_function(a_dictionary_object):
    for _key, _value in a_dictionary_object.items():
        print( get_indentifier_name_missing_function(a_dictionary_object)    +
               "    " +
               str(_key) +
               "  =  " +
               str(_value) )
######
```

Expected results would be:

```python
some_dictionary_1    definition_1  =  text_1
some_dictionary_1    definition_2  =  text_2
some_dictionary_1    etc  =  etc.
some_other_dictionary_2    key_3  =  value_3
some_other_dictionary_2    key_4  =  value_4
some_other_dictionary_2    etc  =  etc.
......
......
......
some_other_dictionary_n    random_n  =  random_n
some_other_dictionary_n    etc  =  etc.
```

Unfortunately, `get_indentifier_name_missing_function()` would not see the 'original' identifier names (`some_dictionary_`,`some_other_dictionary_2`,`some_other_dictionary_n`). It would only see the `a_dictionary_object` identifier name.

Therefore the real result would rather be:

```python
a_dictionary_object    definition_1  =  text_1
a_dictionary_object    definition_2  =  text_2
a_dictionary_object    etc  =  etc.
a_dictionary_object    key_3  =  value_3
a_dictionary_object    key_4  =  value_4
a_dictionary_object    etc  =  etc.
......
......
......
a_dictionary_object    random_n  =  random_n
a_dictionary_object    etc  =  etc.
```

So, the reverse of the `eval()` function won't be that useful in this case.

---

Currently, one would need to do this:

```python
# main2.py same as above, except:

    for each_one_of_my_dictionaries_names in ( 'some_dictionary_1',
                                               'some_other_dictionary_2',
                                               '...',
                                               'some_other_dictionary_n' ):
        some_module2.some_function( { each_one_of_my_dictionaries_names :
                                     eval(each_one_of_my_dictionaries_names) } )

    # some_module2.py
    def some_function(a_dictionary_name_object_container):
        for _dictionary_name, _dictionary_object in a_dictionary_name_object_container.items():
            for _key, _value in _dictionary_object.items():
                print( str(_dictionary_name) +
                       "    " +
                       str(_key) +
                       "  =  " +
                       str(_value) )
    ######
```

---

## Conclusion

- Python passes only memory addresses as arguments to functions.
- Strings representing the name of an identifier, can only be referenced back to the actual identifier by the `eval()` function if the name identifier is available in the current namespace.
- A hypothetical reverse of the `eval()` function, would not be useful in cases where the identifier name is not 'seen' directly by the calling code. E.g. inside any called function.
- Currently one needs to pass to a function:
  1. the string representing the identifier name
  2. the actual identifier (memory address)

This can be achieved by passing both the `'string'` and `eval('string')` to the called function at the same time. I think this is the most 'general' way of solving this egg-chicken problem across arbitrary functions, modules, namespaces, without using corner-case solutions. The only downside is the use of the `eval()` function which may easily lead to unsecured code. Care must be taken to not feed the `eval()` function with just about anything, especially unfiltered external-input data.

## Okay. Let's use python-varname

> [python-varname](https://github.com/pwwang/python-varname)
