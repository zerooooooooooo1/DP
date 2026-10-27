#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;regex&gt;
using namespace std;
bool validateEmail(const string&amp; email) {

regex pattern(R&quot;([a-zA-Z0-9._%-]+@[a-zA-Z0-9.-]+\.[a-zA-
Z]{2,})&quot;);
return regex_match(email, pattern);
}
bool validateAge(int age) {
return age &gt;= 1 &amp;&amp; age &lt;= 120;
}
int main() {
string email = &quot;user@example.com&quot;;
int age = 25;
cout &lt;&lt; &quot;Email valid: &quot; &lt;&lt; (validateEmail(email) ? &quot;YES&quot; :
&quot;NO&quot;) &lt;&lt; endl;
cout &lt;&lt; &quot;Age valid: &quot; &lt;&lt; (validateAge(age) ? &quot;YES&quot; : &quot;NO&quot;)
&lt;&lt; endl;  
string bad = &quot;notanemail&quot;;
int bad_age = -5;
cout &lt;&lt; &quot;Bad email valid: &quot; &lt;&lt; (validateEmail(bad) ? &quot;YES&quot; :
&quot;NO&quot;) &lt;&lt; endl;
cout &lt;&lt; &quot;Bad age valid: &quot; &lt;&lt; (validateAge(bad_age) ? &quot;YES&quot; :
&quot;NO&quot;) &lt;&lt; endl;
return 0;
}
