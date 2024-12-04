# Eagle233-Blog

> I'm not very good at English so all of the contents below are mostly translated from Chinese to English using gpt-4o-mini.

[GitHub](https://github.com/Eagle233Fake/eagle233fake.github.io)
[Pages](https://blog.eagle233.top/)
[Video Demo](https://www.youtube.com/watch?v=xkUwLzIbpP4)

## Thoughs

Honestly, this project was not created after completing the CS50x course. Initially, this blog was meant to document some reflections and insights from my life and studies, but it gradually evolved into notes for CS50x.
The moment I was admitted to the Software Engineering program at East China Normal University, I knew I was entering the world of computer science that I had long anticipated. At that time, CS50x happened to provide me with an introductory course. Therefore, I decided to use my blog as my final project.
Starting around September 15th, I began using this blog as my study notes for CS50x. During more than two months of study, I experienced the pressure of schoolwork, but ultimately I decided to return to the study of computer science, which I love the most. I cannot force myself to be an academic powerhouse, but I can do my best to love the field I pursue, just like when I filled out my college application during the college entrance examination; I resolutely chose the computer science major without considering any other options.

## Implementation

First, I would like to thank two projects: [Hexo](https://github.com/hexojs) and [tobylai-toby/hexo-theme-mdsuper](https://github.com/tobylai-toby/hexo-theme-mdsuper). Hexo built my blog, and mdsuper is the theme for my website. Hexo is based on npm, so you may need to install npm to deploy it properly.

### Source `/source`

- In `/source/_posts`, most of my article notes are stored.
- In `/source/categories`, the articles are categorized, including summaries and CS50x, CS106L.
- In `/source/about`, there is the introduction to myself, which has not been done yet.

### Image `/images`

- Here are the photos needed for my notes. I use [sm.ms](sm.ms) as the image hosting service.

### Theme `/themes`

- Using [tobylai-toby/hexo-theme-mdsuper](https://github.com/tobylai-toby/hexo-theme-mdsuper) as my theme with Material Design 3.

### Modules `/node_modules`

- This part is not frequently modified manually, but it contains the plugins needed for the website.

### Public `/public`

- A static webpage deployed on GitHub Pages.

### Scaffolds `/scaffolds`

- Templates for different articles.

### Config `/_config.yml`

- The most important configuration file for the blog.

## Simple Usages

- To clean the cache:

```bash
hexo clean
```

- To generate:

```bash
hexo g
```

- To deploy to GitHub:

```bash
hexo d
```

- To start a local server:

```bash
hexo s
```

- To post a passage:

```bash
hexo new post "name"
```

## What Does This Have to Do with the CS50x Course?

Building this website is relatively straightforward and doesn't require much prior knowledge. However, when it comes to maintenance, having essential front-end knowledge becomes particularly important. After studying the front-end content in CS50x, the problems I encountered before seem to be easily resolved now. Thanks to CS50x, I have come to understand the meanings of the codes in HTML, CSS, and JS files that were previously difficult to grasp.

## I Also Did:

- Used GitHub Pages to deploy my static website.
- Purchased a domain name `eagle233.top` on [Alibaba Cloud](https://www.aliyun.com/) and used it as the address for my blog.
- Used Git for version control.

## Future

In the future, this blog will continue to serve as my learning notes hosting site. I will embrace the philosophy of 'teaching us how to program' from CS50x to learn more CS courses and improve the blog.
