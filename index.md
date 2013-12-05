---
layout: page
title: Home
tagline: Supporting tagline
---
{% include JB/setup %}

{% for category in site.categories %} 
<h2 id="{{ category[0] }}-ref">{{ category[0] | join: "/" }}</h2>
<ul>
{% assign pages_list = category[1] %}
{% include JB/pages_list %}
</ul>
{% endfor %}
