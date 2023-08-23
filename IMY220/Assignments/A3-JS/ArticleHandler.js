//James Cooks u21654680
//TASK 1
//ArticleHandler class
function ArticleHandler(articles) {
    this.articles = articles;

    this.getArticlesbetweenViews = function (min,max) {
        return articles.filter(function (article) {
            return article.views >= min && article.views <= max;
        });
    }

    this.getByMonth = function (month) {
        return articles.filter(function (article) {
            return new Date(article.date).getMonth() + 1 === month;
        });
    }

    this.getUniqueRatingAndSort = function () {
        const sortArticles = articles.sort(function (a, b) {
          const dateA = new Date(a.date);
          const dateB = new Date(b.date);
          return dateA.getMonth() - dateB.getMonth();
        });
      
        const uniqueRatedArticles = sortArticles.reduce(function (acc, curr) {
          if (!acc.ratings.includes(curr.rating)) {
            acc.ratings.push(curr.rating);
            acc.result.push(curr);
          }
          return acc;
        }, { ratings: [], result: [] }).result;
      
        return uniqueRatedArticles;
      }

    this.getSummary = function(...articleList) {
      const articles = articleList.length > 0 ? articleList : this.articles;
      return articles.map(article => {
        const ratingText = article.rating > 3.5 ? "loved by all!" : "not highly rated";
        return `'${article.title}' was published on ${article.date} by ${article.author}. It was viewed ${article.views} times and was ${ratingText}`;
      });
    }

}

//TASK 2
//Extending array prototype so that functions can be chained
Array.prototype.getArticlesBetweenViews = function(minViews, maxViews) {
  return this.filter(article => article.views >= minViews && article.views <= maxViews);
};

Array.prototype.getByMonth = function(month) {
  return this.filter(article => new Date(article.date).getMonth() + 1 === month);
};

Array.prototype.getUniqueRatingAndSort = function() {
  const uniqueRatings = new Set();
  return this
    .filter(article => {
      if (!uniqueRatings.has(article.rating)) {
        uniqueRatings.add(article.rating);
        return true;
      }
      return false;
    })
    .sort((a, b) => new Date(a.date) - new Date(b.date));
};

Array.prototype.getSummary = function() {
  const articles = arguments.length > 0 ? Array.from(arguments) : this;
  return articles.map(article => {
    const ratingText = article.rating > 3.5 ? "loved by all!" : "not highly rated";
    return `'${article.title}' was published on ${article.date} by ${article.author}. It was viewed ${article.views} times and was ${ratingText}`;
  });
};