import jieba

with open('释放创新动能引领新质生产力发展.txt', 'r', encoding='utf-8') as f:
    text = f.read()

words = jieba.lcut(text)
word_counts = {}

for word in words:
    word_counts[word] = word_counts.get(word, 0) + 1

sorted_words = sorted(word_counts.items(), key=lambda x: x[1], reverse=True)

for word, count in sorted_words[:10]:
    print(f"{word}一词出现{count}次")