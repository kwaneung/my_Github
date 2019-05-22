a = "Life is too short, you need python"
if 'wife' in a:  # False
    print('wife')
elif 'python' in a and 'you' not in a:  # False
    print('python')
elif 'shirt' not in a:  # True
   print('shirt')
elif 'need' in a:  # True
    print('need')
else:
    print('none')