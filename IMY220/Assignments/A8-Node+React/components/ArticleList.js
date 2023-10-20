import React, { Component } from 'react';
import PropTypes from 'prop-types';
import Article from './Article';
import DateForm from './DateForm';

class ArticleList extends Component {
  constructor(props) {
    super(props);
    this.state = {
      currentDate: props.theDate,
    };
  }

  handleDateChange = (newDate) => {
    this.setState({ currentDate: newDate });
  };

  render() {
    const { articles } = this.props;
    const { currentDate } = this.state;

    const filteredArticles = articles.filter((article) => article.date === currentDate);

    return (
      <div>
        <DateForm onDateChange={this.handleDateChange} />
        <h2>Articles on {currentDate}</h2>
        {filteredArticles.length === 0 && <h3>No articles found for {currentDate}</h3>}
        {filteredArticles.length > 0 && (
          <div>
            <div className="row">
              {filteredArticles.map((article, index) => (
                <div key={index} className="col-md-4">
                  <Article article={article} />
                </div>
              ))}
            </div>
          </div>
        )}
      </div>
    );
  }
}

ArticleList.propTypes = {
  articles: PropTypes.arrayOf(
    PropTypes.shape({
      name: PropTypes.string.isRequired,
      description: PropTypes.string.isRequired,
      date: PropTypes.string.isRequired,
    })
  ).isRequired,
};

export default ArticleList;
