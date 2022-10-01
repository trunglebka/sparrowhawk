from cgitb import text
import re
from typing import List, Set
import unicodedata


RE_DOUBLE_QUOTE_WITHOUT_ESCAPE_PATTERN = re.compile(r'(?<!\\)"', re.UNICODE)
RE_SINGLE_QUOTE_WITHOUT_S_PATTERN = re.compile(r"'(?!s)", re.UNICODE)
RE_NEXT_LINE_CHARS_PATTERN = re.compile(r"(\r\n|\n)+", re.UNICODE)
RE_MULTI_WHITESPACES_PATTERN = re.compile(" +")

SPECIAL_CHARS_TOBE_REMOVED = set(
    "\u200B \\ （ ）´ ` ̆ ^ ̊ ¨ ̇ ÷ × ≠ ≤ ≥ ¬ | µ ─ ¯ \u00AD ¡ ¿ · ¸ ‘ ’ « » ⁻ § © ® ™ ¢ # ← → ↑ ↓ ʌ ɪ ˈ ɑ ː ʃ ʊ ɝ ɡ ̛ ̂ ɚ ɜ ˌ ɒ ʤ ̬ ̩ ɾ ˚ ʳ ȼ ˴ ƞ ɴ ɬ ɧ ɳ ɣ ɨ ɮ ɂ ˳ ɫ ɢ ɩ ˡ ɭ ɏ ȵ ˠ ʰ ɋ ʡ ȴ ɶ ˢ ɰ ɯ ɤ ɲ ̈ ƒ ɉ ɱ ɕ ɐ ˪ ɍ ɥ ƃ ʇ ʎ ɟ ɹ ˹ ƀ ɸ ˽ ɇ ȸ ȶ ɷ ǁ ; ݔ ݎ ̴ ʻ ̀ ́ ͟ ͜ ʖ ͡ ͞ ∫ • \uFEFF — \u2028 − \u200E ✔ √ ♦ ▪ ▲ ▼ ≈ 　 ≡ ′ ∞ ″ ♥ „ № ⁄ ‰   \uF02A ⇒   ： \u2029 ⓱ ◊ \uF02E わ た し は ご ん を べ ま す › ℝ ᶥ ᶧ \u1DF7 ᷝ ᶡ ᷓ ᷍ ᷇ ᷋ \u1DEB ℅   \u200F ⅕ ‐ ￼ ᷁ ᶿ ᶣ \u1DE7 ∝ ✓ ✌ ᷉ ᷛ ᷑ \uF0B7 ● † ᷕ ᶯ ᷙ ᷣ ᶭ \u1DEF ᶽ ᶩ \u1DF3 \uF0E0 \uF0BC \u1DF9 ᷥ ᷃ \u1DED ☺ จ ู บ ᷗ ᶱ ， ส ย า ม พ ร ก อ น ท ่ ศ ุ ว ณ ภ ิ ᶷ \u1DE9 ℓ ⅓ ᷟ ᷅ ‑ \uF8FF ᷡ \u1DF1 ᶻ \u202A ∑ ‚ \u202C ★ ⠀   ＋   \uF061 䕯 「 な だ 、 」 － ＿ 〈 ｃ ⅔ � \b \u001C \u007F \u0085 \u0091 \u0092 \u0093 \u0094 \u0096 ⁰ ¼ ½ ¾ ¹ ² ³ ⁶ ǎ å ä ȧ ǡ ą ā ȁ ȃ ª æ ǽ ǣ ɓ ć č ċ ç ɖ ð ǳ ĕ ě ë ė ȩ ę ē ə ɛ ǝ ǵ ğ ġ ģ ƣ ħ ĭ î ï į ī ȉ ȋ ı ĳ ĵ ǩ ķ ĺ ł ļ ń ǹ ň ñ ņ ŋ ŏ ö ɵ ő ȭ ȯ ȱ ø ǫ ǭ ō ȍ ɔ º œ ĸ ŕ ř ŗ ȑ ś š ş ș ṣ ß ť ŧ ț ţ ŭ û ů ü ű ų ū ŵ ŷ ÿ ź ž þ ʒ ב ה ו ט י ל α β γ δ ε η θ ι ί κ λ μ ν ο π ρ σ ς τ υ ύ φ ω а б в г д е ә є ё ж з ӡ и й к л м н о п р с т у ф х ц ш щ ъ ы ь э я   上 下 件 何 侠 停 先 克 八 几 出 別 力 助 卸 口 命 国 坠 坦 墨 壇 多 大 天 奔 子 宣 家 尻 川 幫 年 弁 弹 强 当 彩 德 性 战 手 找 投 拜 掷 操 方 明 曲 會 月 机 来 桃 桌 棍 機 氏 水 洪 滚 点 玩 球 生 画 発 發 百 碼 票 禮 私 篮 紅 組 總 绘 绝 美 耻 聯 號 製 計 證 賣 遭 隨 電 食 飯 騷 體".split()
)
assert "'" not in SPECIAL_CHARS_TOBE_REMOVED
PUNCT_CHARS = set("!:;,.?")

NOT_IMPORTANT_MARKS = set(""">/\<@#$%^&*()+-="{}[]|""")

MONEY_CURRENCIES = "$ $ US$ ฿ £ € ₩ nzd rs chf dkk fim aed ¥ czk mro pkr crc hk$ npr awg nok tzs sek cyp r sar cve rsd dm shp php cad ssp scr mvr DH Dh Dhs. VNĐ ₫".split()
RE_MONEY_CURRENCIES = "|".join(MONEY_CURRENCIES)
RE_CARDINAL = "[1-9][0-9]{0,2}(?:,[0-9]{3}){0,3}"
RE_MONEY_RANGE_PATTERN = re.compile(
    f"({RE_MONEY_CURRENCIES})({RE_CARDINAL})-({RE_CARDINAL})"
)


def pre_norm_money_range(text: str) -> str:
    return re.sub(RE_MONEY_RANGE_PATTERN, r"\2 to \1\3", text)


def detach_punct_chars(text: str) -> str:
    out = ""
    for c in text:
        if c in PUNCT_CHARS:
            out += f" {c} "
        else:
            out += c
    return out


def remove_redundant_spaces(text: str) -> str:
    return re.sub(RE_MULTI_WHITESPACES_PATTERN, " ", text.strip())


def remove_not_important_marks(text: str) -> str:
    out = ""
    for i in range(len(text)):
        c = text[i]
        # ...he's
        if c == "'" and text[i + 1 : i + 2] != "s":
            out += " "
        else:
            out += c
    return remove_special_chars(out, NOT_IMPORTANT_MARKS, repl=" ")


def split_text_to_lines(text: str) -> List[str]:
    return re.split(RE_NEXT_LINE_CHARS_PATTERN, text.strip())


def norm_unicode(text: str) -> str:
    return unicodedata.normalize("NFC", text)


def standardize_quote(text: str) -> str:
    text = text.replace("“", '"').replace("”", '"').replace("’", "'")
    return text


def remove_special_chars(
    text: str, special_chars_set: Set[str] = SPECIAL_CHARS_TOBE_REMOVED, repl=" "
):
    text = text
    out = ""
    for c in text:
        if c in special_chars_set:
            out += repl
        else:
            out += c
    return out


def escapse_double_quote(text: str) -> str:
    parts = []
    last_matched_idx = 0
    for m in re.finditer(RE_DOUBLE_QUOTE_WITHOUT_ESCAPE_PATTERN, text):
        parts.append(text[last_matched_idx : m.start()])
        parts.append(r"\"")
        last_matched_idx = m.end()
    if last_matched_idx < len(text):
        parts.append(text[last_matched_idx:])
    return "".join(parts)


if __name__ == "__main__":
    text = """HÀ NỘI - Paintings and sculptures from the Việt Nam Fine Arts Museum's collection are on display to highlight Vietnamese people's love of learning.
The exhibition entitled Truyền Thống Hiếu Học (Love for Learning - Việt Nam's Great Tradition) features around 50 selected paintings and sculptures.
The paintings are in a wide range of forms from oil on canvas, lacquer, silk, woodcuts and watercolours while the sculptures are made of wood, plaster and cast iron.
In celebration of the 77th anniversary of Việt Nam’s Independence Day and children returning to school, the museum organised the exhibition aiming to make visitors proud of the tradition of fondness for learning, according to the museum's director Nguyễn Anh Minh.
Soon after very first Independence Day on September 2, 1945, President Hồ Chí Minh wrote a letter to the students to mark the start of the first school year of the newly independent nation, the Democratic Republic of Việt Nam.
In this letter, he declared: “The future of Việt Nam, whether to be glorious or not, and whether to be able to stand with the great powers of the world or not, depends very much on the hard work you put into your studies.”
Inspired by President Hồ's message, a major campaign entitled Bình Dân Học Vụ (Mass Education Movement) was launched to teach illiterate peasants and labourers how to read and write.
During the last half of 1940s, many artists from the Indochina Fine Arts College in Hà Nội travelled to every region to record the study life of this period.
This could be seen in such works as The First Secondary School Class by Diệp Minh Châu, An Adult Literacy Class at Bền Village by Trần Văn Cẩn, and Grandma Dương Can Read by Tô Ngọc Vân.
"The exhibition shows the richness of our national fine arts as they have developed from 1945 to the present day," Minh said at the exhibition opening ceremony.
"Through this exhibition, the museum explores and celebrates our national tradition of passion for learning.
"In doing so, we hope to inspire our young people to embrace this great tradition as handed down from our nation’s past, and to pass on the torch still brightly and eternally burning to those who follow on in years to come."
At the exhibition, the young people will see how older generations studied in wartime in paintings such as Grade 5 Pupils in an Underground Classroom and A Class for Women Guerrillas in Củ Chi. 
During wartime, most schools had to relocate to evacuation zones. Some even held classes underground to ensure that pupils could learn in safety when it was too dangerous to teach and learn on the ground.
When the country was reunified, education was not only confined to schools but expanded to include sharing experiences between colleagues and passing down knowledge and skills to later generations, all depicted in the talent of the painters.
Exhibition goers will value all the ways that learning takes place in schools, as well as other sites and settings. The learning that occurs when people interact with each other or learn alone by themselves.
The exhibition runs until September 11 at 66 Nguyễn Thái Học Street, Hà Nội - VNS
            """
    escaped_text = escapse_double_quote(text)
    print(escaped_text)
